class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, 2 * w});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>pq;
        vector<int> minDist(n, 1e9);
        minDist[0] = 0;
        pq.push({0, 0});
        while (!pq.empty()) {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto& it : adj[node]) {
                int v = it.first;
                int w = it.second;
                if (dist + w < minDist[v]) {
                    pq.push({dist + w, v});
                    minDist[v] = dist + w;
                }
            }
        }
        return minDist[n - 1];
    }
};