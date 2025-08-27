class Solution {
public:
    bool isValid(int i, int j, int exp, vector<vector<int>>& grid, int n,
                 int m) {
        return (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == exp);
    }
    int dfs(int r, int c, vector<vector<int>>& grid, int exp, int n, int m,
            int d, int dir[4][4], bool canTurn) {
        int nr = r + dir[d][0];
        int nc = c + dir[d][1];
        if (!isValid(nr, nc, exp, grid, n, m)) {
            return 0;
        }
        int nexp = exp == 2 ? 0 : 2;
        int maxLen1 = 1 + dfs(nr, nc, grid, nexp, n, m, d, dir, canTurn);
        int maxLen2 = -1e9;
        if (canTurn) {
            maxLen2 =
                1 + dfs(nr, nc, grid, nexp, n, m, (d + 1) % 4, dir, false);
        }
        return max(maxLen1, maxLen2);
    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        int dir[4][4] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    for (int d = 0; d < 4; d++) {
                        ans = max(ans,
                                  1 + dfs(i, j, grid, 2, n, m, d, dir, true));
                    }
                }
            }
        }
        return ans;
    }
};