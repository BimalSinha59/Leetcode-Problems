class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& heights,
             vector<vector<int>>& vis, int dr[], int dc[], int n, int m) {

        vis[i][j] = 1;
        for (int k = 0; k < 4; k++) {
            int ni = i + dr[k];
            int nj = j + dc[k];
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && vis[ni][nj] == 0 &&
                heights[ni][nj] >= heights[i][j]) {

                dfs(ni, nj, heights, vis, dr, dc, n, m);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> visp(n, vector<int>(m, 0)),
            visa(n, vector<int>(m, 0));

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        for (int j = 0; j < m; j++) {
            if (visp[0][j] == 0) {
                dfs(0, j, heights, visp, dr, dc, n, m);
            }
            if (visa[n - 1][j] == 0) {
                dfs(n - 1, j, heights, visa, dr, dc, n, m);
            }
        }
        for (int i = 0; i < n; i++) {
            if (visp[i][0] == 0) {
                dfs(i, 0, heights, visp, dr, dc, n, m);
            }
            if (visa[i][m - 1] == 0) {
                dfs(i, m - 1, heights, visa, dr, dc, n, m);
            }
        }
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visp[i][j] && visa[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};