class Solution {
public:
    int m, n;
    int getSum(const vector<vector<int>>& grid, int i, int j, int edge) {
        if (edge == 0)
            return grid[i][j];
        if (i + 2 * edge >= m || j - edge < 0 || j + edge >= n)
            return 0;

        int sum = 0;
        for (int k = 0; k < edge; k++) {
            sum += grid[i + k][j + k] + grid[i + edge + k][j + edge - k] +
                   grid[i + 2 * edge - k][j - k] +
                   grid[i + edge - k][j - edge + k];
        }
        return sum;
    }
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int maximumEdge = (min(m, n) + 1) / 2;
        set<int> topSums;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int edge = 0; edge < maximumEdge; edge++) {
                    int sum = getSum(grid, i, j, edge);
                    if (sum != 0) {
                        topSums.insert(sum);
                        if (topSums.size() > 3) {
                            topSums.erase(topSums.begin());
                        }
                    }
                }
            }
        }
        return vector<int>(topSums.rbegin(), topSums.rend());
    }
};