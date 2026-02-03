class RideSharingSystem {
public:
    queue<int> qr, qd;
    unordered_map<int, int> isCancelled;
    RideSharingSystem() {}

    void addRider(int riderId) {
        qr.push(riderId);
        isCancelled[riderId] = 0;
    }

    void addDriver(int driverId) { qd.push(driverId); }

    vector<int> matchDriverWithRider() {
        while (!qr.empty() && isCancelled[qr.front()] == 1) {
            qr.pop();
        }
        if (qr.empty() || qd.empty()) {
            return {-1, -1};
        }
        int rid = qr.front();
        qr.pop();
        int did = qd.front();
        qd.pop();
        return {did, rid};
    }

    void cancelRider(int riderId) {
        if (isCancelled.find(riderId) != isCancelled.end()) {
            isCancelled[riderId] = 1;
        }
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */