class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int di = n - 1, dj = m - 1;
        int ans = 0;
        while (di >= 0 && dj >= 0) {
            if (grid[di][dj] < 0) {
                ans++;
                for (int i = di - 1; i >= 0; i--) {
                    if (grid[i][dj] < 0) {
                        ans++;
                    } else {
                        break;
                    }
                }
                for (int j = dj - 1; j >= 0; j--) {
                    if (grid[di][j] < 0) {
                        ans++;
                    } else {
                        break;
                    }
                }
            } else {
                break;
            }
            di--;
            dj--;
        }
        return ans;
    }
};