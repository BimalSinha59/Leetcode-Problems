class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj,
             int& no_of_vertices, int& no_of_edges) {
        vis[node] = 1;
        no_of_vertices++;
        no_of_edges += adj[node].size();
        for (auto& it : adj[node]) {
            if (!vis[it]) {
                dfs(it, vis, adj, no_of_vertices, no_of_edges);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n, 0);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int no_of_vertices = 0, no_of_edges = 0;
                dfs(i, vis, adj, no_of_vertices, no_of_edges);
                if (no_of_edges == no_of_vertices * (no_of_vertices - 1)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};