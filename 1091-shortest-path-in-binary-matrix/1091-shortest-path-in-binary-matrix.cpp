class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dis(n, vector<int>(n, 1e9));
        queue<vector<int>> q;
        if (grid[0][0] == 0) {
            q.push({0, 0, 0});
        }
        dis[0][0] = 0;
        while (!q.empty()) {
            auto cell = q.front();
            int dist = cell[0];
            int r = cell[1];
            int c = cell[2];
            q.pop();
            if (r == n - 1 && c == n - 1 && grid[r][c] == 0) {
                return dist + 1;
            }
            for (int dr = -1; dr <= 1; dr++) {
                for (int dc = -1; dc <= 1; dc++) {
                    int nr = r + dr;
                    int nc = c + dc;
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                        grid[nr][nc] == 0) {
                        if (dist + 1 < dis[nr][nc]) {
                            q.push({dist + 1, nr, nc});
                            dis[nr][nc] = dist + 1;
                        }
                    }
                }
            }
        }
        return -1;
    }
};