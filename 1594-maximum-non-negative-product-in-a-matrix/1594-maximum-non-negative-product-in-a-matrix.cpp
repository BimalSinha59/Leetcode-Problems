class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<pair<long long, long long>>>dp;
    pair<long long, long long> solve(int i, int j, int n, int m, vector<vector<int>>& grid) {
        if (i == n - 1 && j == m - 1) {
            return {grid[i][j], grid[i][j]};
        }
        if(dp[i][j]!=make_pair(LLONG_MIN, LLONG_MAX)){
            return dp[i][j];
        }
        long long maxVal = LLONG_MIN, minVal = LLONG_MAX;
        if (i + 1 < n) {
            auto [downMax, downMin] = solve(i + 1, j, n, m, grid);
            maxVal = max({maxVal, grid[i][j] * downMax, grid[i][j] * downMin});
            minVal = min({minVal, grid[i][j] * downMax, grid[i][j] * downMin});
        }
        if (j + 1 < m) {
            auto [rightMax, rightMin] = solve(i, j + 1, n, m, grid);
            maxVal = max({maxVal, grid[i][j] * rightMax, grid[i][j] * rightMin});
            minVal = min({minVal, grid[i][j] * rightMax, grid[i][j] * rightMin});
        }
        return dp[i][j] = {maxVal, minVal};
    }
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        dp=vector<vector<pair<long long, long long>>>(n, vector<pair<long long, long long>>(m, {LLONG_MIN, LLONG_MAX}));
        auto [maxRes, minRes] = solve(0, 0, n, m, grid);
        return maxRes < 0 ? -1 : maxRes % MOD;
    }
};