class Solution {
    bool isValid(int nr, int nc, int n) {
        return nr >= 0 && nr < n && nc >= 0 && nc < n;
    }

public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>pq;
        pq.push({grid[0][0], {0, 0}});
        int ans = grid[0][0];
        vis[0][0] = 1;
        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};
        while (!pq.empty()) {
            int val = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            ans = max(ans, val);
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (isValid(nr, nc, n) && !vis[nr][nc]) {
                    if (nr == n - 1 && nc == n - 1) {
                        return max(ans, grid[nr][nc]);
                    }
                    vis[nr][nc] = 1;
                    pq.push({grid[nr][nc], {nr, nc}});
                }
            }
        }
        return ans;
    }
};