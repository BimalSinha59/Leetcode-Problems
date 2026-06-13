class Solution {
    int timer = 1;

public:
    void dfs(int node, int parent, vector<vector<int>>& adjL, vector<int>& vis,
             vector<int>& tin, vector<int>& tmin,
             vector<vector<int>>& bridges) {
        vis[node] = 1;
        tin[node] = tmin[node] = timer;
        timer++;
        for (auto& it : adjL[node]) {
            if (it == parent) {
                continue;
            }
            if (!vis[it]) {
                dfs(it, node, adjL, vis, tin, tmin, bridges);
                tmin[node] = min(tmin[it], tmin[node]);
                if (tmin[it] > tin[node]) {
                    bridges.push_back({it, node});
                }
            } else {
                tmin[node] = min(tmin[it], tmin[node]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adjL(n);
        for (auto& connection : connections) {
            int u = connection[0];
            int v = connection[1];
            adjL[u].push_back(v);
            adjL[v].push_back(u);
        }
        vector<int> vis(n, 0);
        vector<vector<int>> bridges;
        vector<int> tin(n);
        vector<int> tmin(n);
        dfs(0, -1, adjL, vis, tin, tmin, bridges);
        return bridges;
    }
};