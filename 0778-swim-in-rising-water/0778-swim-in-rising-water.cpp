class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>pq;
                       
        pq.push({grid[0][0], {0, 0}});
        int di[] = {-1, 0, 1, 0};
        int dj[] = {0, 1, 0, -1};
        int ans = 0;
        while (!pq.empty()) {
            int time = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            if (vis[i][j]) {
                continue;
            }
            vis[i][j] = 1;
            ans = max(ans, time);

            if (i == n - 1 && j == n - 1) {
                return ans;
            }
            for (int k = 0; k < 4; k++) {
                int ni = i + di[k];
                int nj = j + dj[k];
                if (ni >= 0 && ni < n && nj >= 0 && nj < n && !vis[ni][nj]) {
                    pq.push({grid[ni][nj], {ni, nj}});
                }
            }
        }
        return -1;
    }
};