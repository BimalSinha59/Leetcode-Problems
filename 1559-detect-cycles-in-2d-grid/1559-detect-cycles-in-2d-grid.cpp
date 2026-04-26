class Solution {
public:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    bool dfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& vis,
             int& n, int& m, int li, int lj) {
        vis[i][j] = 1;
        for (int k = 0; k < 4; k++) {
            int ni = i + dr[k];
            int nj = j + dc[k];
            if ((ni != li || nj != lj) && ni >= 0 && ni < n && nj >= 0 &&
                nj < m && grid[ni][nj] == grid[i][j] &&
                (vis[ni][nj] || dfs(ni, nj, grid, vis, n, m, i, j))) {
                return true;
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == 0 && dfs(i, j, grid, vis, n, m, -1, -1)) {
                    return true;
                }
            }
        }
        return false;
    }
};