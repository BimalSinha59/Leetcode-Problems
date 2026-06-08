class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        queue<vector<int>> q;
        if (grid[0][0] == 0) {
            q.push({1, 0, 0});
        }
        vis[0][0] = 1;
        while (!q.empty()) {
            auto cell = q.front();
            int dis = cell[0];
            int r = cell[1];
            int c = cell[2];
            q.pop();
            if (r == n - 1 && c == n - 1 && grid[r][c] == 0) {
                return dis;
            }
            for (int dr = -1; dr <= 1; dr++) {
                for (int dc = -1; dc <= 1; dc++) {
                    int nr = r + dr;
                    int nc = c + dc;
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                        grid[nr][nc] == 0 && !vis[nr][nc]) {
                        q.push({dis + 1, nr, nc});
                        vis[nr][nc] = 1;
                    }
                }
            }
        }
        return -1;
    }
};