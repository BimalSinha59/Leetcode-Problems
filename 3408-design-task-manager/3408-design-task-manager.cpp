struct Mng {
    int userId;
    int taskId;
    int priority;
};

struct Compare {
    bool operator()(const Mng& a, const Mng& b) const {
        if (a.priority == b.priority)
            return a.taskId < b.taskId;
        return a.priority < b.priority;
    }
};

class TaskManager {
private:
    priority_queue<Mng, vector<Mng>, Compare> pq;
    unordered_map<int, Mng> record;

public:
    TaskManager(vector<vector<int>> tasks) {
        for (auto& t : tasks) {
            Mng m{t[0], t[1], t[2]};
            pq.push(m);
            record[t[1]] = m;
        }
    }

    void add(int userId, int taskId, int priority) {
        Mng m{userId, taskId, priority};
        pq.push(m);
        record[taskId] = m;
    }

    void edit(int taskId, int newPriority) {
        if (record.find(taskId) == record.end())
            return;
        Mng old = record[taskId];
        Mng updated{old.userId, taskId, newPriority};
        pq.push(updated);
        record[taskId] = updated;
    }

    void rmv(int taskId) { record.erase(taskId); }

    int execTop() {
        while (!pq.empty()) {
            Mng top = pq.top();
            pq.pop();

            auto it = record.find(top.taskId);
            if (it == record.end())
                continue;
            if (it->second.priority != top.priority)
                continue;

            record.erase(it);
            return top.userId;
        }
        return -1;
    }
};

    /**
     * Your TaskManager object will be instantiated and called as such:
     * TaskManager* obj = new TaskManager(tasks);
     * obj->add(userId,taskId,priority);
     * obj->edit(taskId,newPriority);
     * obj->rmv(taskId);
     * int param_4 = obj->execTop();
     */