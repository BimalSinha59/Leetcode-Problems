class Solution {
public:
    const int MOD = 1e9 + 7;
    int modExp(int x, int n) {
        if (n == 0) {
            return 1;
        }
        if (n & 1) {
            return 1LL * modExp(x, n - 1) * x % MOD;
        }
        return modExp(1LL * x * x % MOD, n / 2);
    }
    void dfs(int node, int par, vector<vector<int>>& adjL, int& maxDepth, int depth) {
        maxDepth = max(maxDepth, depth);
        depth++;
        for (int& adjNode : adjL[node]) {
            if (adjNode == par) {
                continue;
            }
            dfs(adjNode, node, adjL, maxDepth, depth);
        }
        depth = 0;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adjL(n + 2);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adjL[u].push_back(v);
            adjL[v].push_back(u);
        }
        int maxDepth = 0;
        dfs(1, -1, adjL, maxDepth, 0);
        int ans = modExp(2, maxDepth - 1);
        return ans;
    }
};