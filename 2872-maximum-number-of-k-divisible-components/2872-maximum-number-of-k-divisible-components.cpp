class Solution {
public:
    long long dfs(int node, int par, vector<vector<int>>& adj, vector<int>& values,
            int k, int& ans) {

        long long sum = values[node];
        for (auto it : adj[node]) {
            if (it == par) {
                continue;
            }
            long long subt = dfs(it, node, adj, values, k, ans);
            if (subt % k == 0) {
                ans++;
            } else {
                sum += subt;
            }
        }
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                                vector<int>& values, int k) {

        vector<vector<int>> adj(n);
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int ans = 1;
        dfs(0, -1, adj, values, k, ans);
        return ans;
    }
};