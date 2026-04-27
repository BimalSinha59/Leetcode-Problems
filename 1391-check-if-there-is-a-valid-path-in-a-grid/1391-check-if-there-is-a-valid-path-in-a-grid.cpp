class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<pair<int, int>>> dirn(7);
        dirn[1] = {{0, -1}, {0, 1}};
        dirn[2] = {{-1, 0}, {1, 0}};
        dirn[3] = {{0, -1}, {1, 0}};
        dirn[4] = {{0, 1}, {1, 0}};
        dirn[5] = {{0, -1}, {-1, 0}};
        dirn[6] = {{0, 1}, {-1, 0}};
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        q.push({0, 0});
        vis[0][0] = 1;
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            if (r == n - 1 && c == m - 1) {
                return true;
            }
            for (auto [dr, dc] : dirn[grid[r][c]]) {
                int nr = r + dr;
                int nc = c + dc;
                if (nr < 0 || nc < 0 || nr >= n || nc >= m || vis[nr][nc]) {
                    continue;
                }
                for (auto [bdr, bdc] : dirn[grid[nr][nc]]) {
                    if (nr + bdr == r && nc + bdc == c) {
                        vis[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
        }
        return false;
    }
};