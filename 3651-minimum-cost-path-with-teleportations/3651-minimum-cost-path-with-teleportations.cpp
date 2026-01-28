class Solution {
public:
    int minTotalCost(int i, int j, int n, int m, vector<vector<int>>& grid,
                     int k, vector<vector<vector<int>>>& dp) {

        if (i >= n || j >= m) {
            return 1e9;
        }
        if (i == n - 1 && j == m - 1) {
            return 0;
        }
        if (dp[i][j][k] != -1) {
            return dp[i][j][k];
        }
        int cost1 = 1e9, cost2 = 1e9;
        if (i + 1 < n) {
            cost1 = grid[i + 1][j] + minTotalCost(i + 1, j, n, m, grid, k, dp);
        }
        if (j + 1 < m) {
            cost2 = grid[i][j + 1] + minTotalCost(i, j + 1, n, m, grid, k, dp);
        }
        int cost3 = 1e9;
        if (k > 0) {
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < m; y++) {
                    if (x == i && y == j) {
                        continue;
                    }
                    if (grid[x][y] <= grid[i][j]) {
                        cost3 = min(cost3, minTotalCost(x, y, n, m, grid, k - 1, dp));
                    }
                }
            }
        }
        return dp[i][j][k] = min({cost1, cost2, cost3});
    }
    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, -1)));
        return minTotalCost(0, 0, n, m, grid, k, dp);
    }
};