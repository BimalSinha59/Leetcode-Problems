class Solution {
public:
    int bgdt;

    vector<int> merge(const vector<int>& dp1, const vector<int>& dp2) {
        vector<int> next(bgdt + 1, -1e9);
        for (int i = 0; i <= bgdt; i++) {
            if (dp1[i] < 0)
                continue;
            for (int j = 0; i + j <= bgdt; j++) {
                if (dp2[j] < 0)
                    continue;
                next[i + j] = max(next[i + j], dp1[i] + dp2[j]);
            }
        }
        return next;
    }

    void dfs(int u, const vector<vector<int>>& tree, const vector<int>& present,
             const vector<int>& future, vector<vector<vector<int>>>& dp) {

        vector<int> sb(bgdt + 1, -1e9);
        vector<int> bb(bgdt + 1, -1e9);

        sb[0] = 0;
        bb[0] = 0;

        for (int v : tree[u]) {
            dfs(v, tree, present, future, dp);
            sb = merge(sb, dp[v][0]);
            bb = merge(bb, dp[v][1]);
        }

        for (int i = 0; i <= 1; i++) {
            int price = i ? present[u] / 2 : present[u];
            int profit = future[u] - price;

            vector<int> cdp = sb;

            if (price <= bgdt) {
                for (int b = 0; b <= bgdt - price; b++) {
                    if (bb[b] > -1e9) {
                        cdp[b + price] = max(cdp[b + price], bb[b] + profit);
                    }
                }
            }
            dp[u][i] = cdp;
        }
    }

    int maxProfit(int n, vector<int>& present, vector<int>& future,
                  vector<vector<int>>& hierarchy, int budget) {
        bgdt = budget;
        vector<vector<int>> tree(n);
        for (auto& edge : hierarchy) {
            tree[edge[0] - 1].push_back(edge[1] - 1);
        }

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2));

        dfs(0, tree, present, future, dp);

        int ans = 0;
        for (int b = 0; b <= bgdt; b++) {
            ans = max(ans, dp[0][0][b]);
        }
        return ans;
    }
};