class Solution {
public:
    int f(int i, int j, int sum, vector<vector<int>>& grid, int k, int n, int m,
          int& md, vector<vector<vector<int>>>& dp) {
            
        if (i >= n || j >= m) {
            return 0;
        }
        sum = (sum + grid[i][j]) % k;
        if (i == n - 1 && j == m - 1) {
            if (sum % k == 0) {
                return 1;
            } else {
                return 0;
            }
        }
        if (dp[i][j][sum] != -1) {
            return dp[i][j][sum];
        }
        int s1 = f(i + 1, j, sum, grid, k, n, m, md, dp);
        int s2 = f(i, j + 1, sum, grid, k, n, m, md, dp);
        return dp[i][j][sum] = (s1 + s2) % md;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int md = 1e9 + 7;
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(k + 1, -1)));
        return f(0, 0, 0, grid, k, n, m, md, dp);
    }
};