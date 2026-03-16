class Solution {
public:
    int solve(int i, int j, int k, int n, int m, vector<vector<int>>& coins,
              vector<vector<vector<int>>>& dp) {
        if (i == n - 1 && j == m - 1) {
            if (coins[i][j] < 0 && k > 0) {
                return 0;
            }
            return coins[i][j];
        }
        if (i >= n || j >= m) {
            return -1e9;
        }
        if (dp[i][j][k] != INT_MIN) {
            return dp[i][j][k];
        }
        int dans = -1e9, rans = -1e9;
        dans = coins[i][j] + solve(i + 1, j, k, n, m, coins, dp);
        if (coins[i][j] < 0 && k > 0) {
            dans = max(dans, solve(i + 1, j, k - 1, n, m, coins, dp));
        }
        rans = coins[i][j] + solve(i, j + 1, k, n, m, coins, dp);
        if (coins[i][j] < 0 && k > 0) {
            rans = max(rans, solve(i, j + 1, k - 1, n, m, coins, dp));
        }
        return dp[i][j][k] = max(dans, rans);
    }
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size();
        int m = coins[0].size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(3, INT_MIN)));
        return solve(0, 0, 2, n, m, coins, dp);
    }
};