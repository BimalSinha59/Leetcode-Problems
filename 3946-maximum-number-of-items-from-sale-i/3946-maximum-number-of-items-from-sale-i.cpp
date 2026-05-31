class Solution {
public:
    int solve(int idx, int rem_budget, int n, int& mini,
              vector<int>& free_items_cnt, vector<vector<int>>& items,
              vector<vector<int>>& dp) {
        if (idx >= n) {
            return rem_budget / mini;
        }
        if (dp[idx][rem_budget] != -1) {
            return dp[idx][rem_budget];
        }
        int not_take =
            solve(idx + 1, rem_budget, n, mini, free_items_cnt, items, dp);
        int take = 0;
        if (rem_budget >= items[idx][1]) {
            take = free_items_cnt[idx] + solve(idx + 1, rem_budget - items[idx][1],
                                            n, mini, free_items_cnt, items, dp);
        }
        return dp[idx][rem_budget] = max(take, not_take);
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> free_items_cnt(n, 0);
        int mini = 1e9;
        for (int i = 0; i < n; i++) {
            mini = min(mini, items[i][1]);
            for (int j = 0; j < n; j++) {
                if (items[j][0] % items[i][0] == 0) {
                    free_items_cnt[i]++;
                }
            }
        }
        vector<vector<int>> dp(n + 1, vector<int>(budget + 1, -1));
        return solve(0, budget, n, mini, free_items_cnt, items, dp);
    }
};