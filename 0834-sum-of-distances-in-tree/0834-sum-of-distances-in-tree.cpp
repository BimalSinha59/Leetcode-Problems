class Solution {
public:
    void dfs(int node, int parent, vector<int> adj[], vector<int>& ncnt,
             vector<int>& ans) {

        for (auto child : adj[node]) {
            if (child == parent) {
                continue;
            }
            dfs(child, node, adj, ncnt, ans);
            ncnt[node] += ncnt[child];
            ans[node] += ans[child] + ncnt[child];
        }
        ncnt[node]++;
    }

    void dfs1(int node, int parent, vector<int> adj[], vector<int>& ncnt,
              vector<int>& ans, int n) {
        for (auto child : adj[node]) {
            if (child == parent) {
                continue;
            }
            ans[child] = ans[node] + n - 2 * ncnt[child];
            dfs1(child, node, adj, ncnt, ans, n);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> ncnt(n, 0), ans(n, 0);
        dfs(0, -1, adj, ncnt, ans);
        dfs1(0, -1, adj, ncnt, ans, n);
        return ans;
    }
};