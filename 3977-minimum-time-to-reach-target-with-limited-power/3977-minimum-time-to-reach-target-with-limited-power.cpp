class Solution {
public:
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v, w});
        }
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> pq;
        vector<vector<long long>> dist(n, vector<long long>(power + 1, 1e18));
        dist[source][power] = 0;
        pq.push({0, source, power});
        long long minTime = -1, maxPower = -1;
        while (!pq.empty()) {
            auto v = pq.top();
            pq.pop();
            long long time = v[0], u = v[1], remPower = v[2];
            if (time != dist[u][remPower]) {
                continue;
            }
            if (minTime != -1 && time > minTime) {
                break;
            }
            if (u == target) {
                if (minTime == -1) {
                    minTime = time;
                }
                maxPower = max(maxPower, remPower);
                continue;
            }
            if (remPower < cost[u]) {
                continue;
            }
            long long nextPower = remPower - cost[u];
            for (auto& adjNode : adj[u]) {
                long long v = adjNode.first, w = adjNode.second;
                long long nTime = time + w;
                if (nTime < dist[v][nextPower]) {
                    dist[v][nextPower] = nTime;
                    pq.push({nTime, v, nextPower});
                }
            }
        }
        return {minTime, maxPower};
    }
};