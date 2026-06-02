class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<vector<int>> q;
        int fresh_count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    vis[i][j] = 1;
                    q.push({i, j, 0});
                } else if (grid[i][j] == 1) {
                    fresh_count++;
                }
            }
        }
        int min_time = 0;
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};
        int count = 0;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            int r = node[0];
            int c = node[1];
            int time = node[2];
            min_time = max(min_time, time);
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc] && grid[nr][nc] == 1) {
                    count++;
                    vis[nr][nc] = 1;
                    q.push({nr, nc, time + 1});
                }
            }
        }
        return fresh_count == count ? min_time : -1;
    }
};