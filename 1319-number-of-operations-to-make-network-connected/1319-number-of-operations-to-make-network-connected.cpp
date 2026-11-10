
class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<bool>& vis) {
        vis[node] = true;
        for (auto adjNode : adj[node]) {
            if (!vis[adjNode]) {
                dfs(adjNode, adj, vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int total_connections = connections.size();
        if (total_connections < n - 1) {
            return -1;
        }
        vector<int> adj[n];
        for (auto connection : connections) {
            int u = connection[0];
            int v = connection[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(n, false);
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis);
                result++;
            }
        }
        return result - 1;
    }
};