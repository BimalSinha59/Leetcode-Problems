class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = INT_MIN;
        for (int i = 0; i < m; i++) {
            int curr = grid[i][0];
            for (int j = 1; j < n; j++) {
                int sum = grid[i][j] + curr;
                ans = max(ans, sum);
                if (i > 0 && i < m - 1 && j > 0 && j < n - 1) {
                    ans = max(ans, grid[i][j]);
                }
                curr = max(grid[i][j], curr + grid[i][j]);
            }
        }
        for (int j = 0; j < n; j++) {
            int curr = grid[0][j];
            for (int i = 1; i < m; i++) {
                int sum = grid[i][j] + curr;
                ans = max(ans, sum);
                if (i > 0 && i < m - 1 && j > 0 && j < n - 1) {
                    ans = max(ans, grid[i][j]);
                }
                curr = max(grid[i][j], curr + grid[i][j]);
            }
        }
        return ans;
    }
};