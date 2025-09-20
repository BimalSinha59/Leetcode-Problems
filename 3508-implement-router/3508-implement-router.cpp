struct TripleHash {
    size_t operator()(const tuple<int, int, int>& t) const {
        auto [a, b, c] = t;
        return ((size_t)a * 1315423911u) ^ ((size_t)b << 16) ^ c;
    }
};

struct Packet {
    int source, destination, timestamp;
};

class Router {
private:
    int maxMemory;
    deque<Packet> dq;
    unordered_set<tuple<int, int, int>, TripleHash> st;

    unordered_map<int, vector<int>> destTimes;

    unordered_map<int, vector<int>> removedTimes;

public:
    Router(int memoryLimit) { maxMemory = memoryLimit; }

    bool addPacket(int source, int destination, int timestamp) {
        tuple<int, int, int> key = {source, destination, timestamp};
        if (st.count(key))
            return false;

        if ((int)dq.size() == maxMemory) {
            Packet old = dq.front();
            dq.pop_front();
            st.erase({old.source, old.destination, old.timestamp});
            removedTimes[old.destination].push_back(old.timestamp);
        }

        dq.push_back({source, destination, timestamp});
        st.insert(key);
        destTimes[destination].push_back(timestamp);
        return true;
    }

    vector<int> forwardPacket() {
        if (dq.empty())
            return {};
        Packet p = dq.front();
        dq.pop_front();
        st.erase({p.source, p.destination, p.timestamp});
        removedTimes[p.destination].push_back(p.timestamp);
        return {p.source, p.destination, p.timestamp};
    }

    int getCount(int destination, int startTime, int endTime) {
        if (!destTimes.count(destination))
            return 0;

        auto& vec = destTimes[destination];
        int total = upper_bound(vec.begin(), vec.end(), endTime) -
                    lower_bound(vec.begin(), vec.end(), startTime);

        if (!removedTimes.count(destination))
            return total;

        auto& rem = removedTimes[destination];
        int removed = upper_bound(rem.begin(), rem.end(), endTime) -
                      lower_bound(rem.begin(), rem.end(), startTime);

        return total - removed;
    }
};
