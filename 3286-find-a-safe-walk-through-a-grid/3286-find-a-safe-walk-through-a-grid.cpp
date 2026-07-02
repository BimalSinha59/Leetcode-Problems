class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        pq.push({grid[0][0], 0, 0});
        vector<vector<int>> dis(m, vector<int>(n, -1));
        int dr[4] = {0, 1, 0, -1};
        int dc[4] = {1, 0, -1, 0};
        while (!pq.empty()) {
            auto cell = pq.top();
            pq.pop();
            int val = cell[0], i = cell[1], j = cell[2];
            if (dis[i][j] >= 0) {
                continue;
            }
            dis[i][j] = val;
            for (int k = 0; k < 4; k++) {
                int ni = i + dr[k];
                int nj = j + dc[k];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n &&
                    dis[ni][nj] == -1) {
                    pq.push({val + grid[ni][nj], ni, nj});
                }
            }
        }
        return dis[m - 1][n - 1] < health;
    }
};