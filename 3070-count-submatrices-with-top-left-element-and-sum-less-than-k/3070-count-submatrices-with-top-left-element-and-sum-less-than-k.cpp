class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> psum(n, vector<int>(m, 0));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            psum[i][0] = grid[i][0];
            if (i - 1 >= 0) {
                psum[i][0] += psum[i - 1][0];
            }
            if (psum[i][0] <= k) {
                ans++;
            }
        }
        for (int j = 0; j < m; j++) {
            psum[0][j] = grid[0][j];
            if (j - 1 >= 0) {
                psum[0][j] += psum[0][j - 1];
            }
            if (j != 0 && psum[0][j] <= k) {
                ans++;
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                psum[i][j] = grid[i][j] + psum[i - 1][j] + psum[i][j - 1] -psum[i - 1][j - 1];
                if (psum[i][j] <= k) {
                    ans++;
                }
            }
        }
        return ans;
    }
};