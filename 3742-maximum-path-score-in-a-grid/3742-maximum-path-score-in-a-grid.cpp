class Solution {
public:
    int solve(int i, int j, int k, vector<vector<int>>& grid, int n, int m,
              vector<vector<vector<int>>>& dp) {
        if (i >= n || j >= m || k < 0)
            return -1e9;
        int cost = (grid[i][j] == 0) ? 0 : 1;
        int score = grid[i][j];
        if (k - cost < 0)
            return -1e9;
        if (i == n - 1 && j == m - 1)
            return score;
        if (dp[i][j][k] != -1)
            return dp[i][j][k];
        int remaining = k - cost;
        int down = score + solve(i + 1, j, remaining, grid, n, m, dp);
        int right = score + solve(i, j + 1, remaining, grid, n, m, dp);
        return dp[i][j][k] = max(down, right);
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, -1)));
        int ans = solve(0, 0, k, grid, n, m, dp);
        return (ans <= -1e8) ? -1 : ans;
    }
};