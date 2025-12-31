class Solution {
public:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    bool canCross(int row, int col, vector<vector<int>>& cells, int n, int mid) {
        vector<vector<int>> grid(row, vector<int>(col, 0));
        for (int i = 0; i < mid; i++) {
            grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
        }
        queue<pair<int, int>> q;
        for (int i = 0; i < col; i++) {
            if (grid[0][i] == 0) {
                q.push({0, i});
                grid[0][i] = 1;
            }
        }
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            if (r == row - 1) {
                return true;
            }
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < row && nc >= 0 && nc < col &&
                    grid[nr][nc] == 0) {
                    grid[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n = cells.size();
        int s = 0, e = n - 1;
        int ans = 0;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (canCross(row, col, cells, n, mid)) {
                ans = mid;
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return ans;
    }
};