class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sum += grid[i][j];
            }
        }
        long long sum1 = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sum1 += grid[i][j];
            }
            if (sum1 == sum - sum1) {
                return true;
            }
        }
        sum1 = 0;
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                sum1 += grid[i][j];
            }
            if (sum1 == sum - sum1) {
                return true;
            }
        }
        return false;
    }
};