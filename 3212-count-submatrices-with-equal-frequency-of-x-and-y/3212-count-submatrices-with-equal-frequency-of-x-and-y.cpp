class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<pair<int, int>>> pcnt(n, vector<pair<int, int>>(m));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int lxcnt = j - 1 >= 0 ? pcnt[i][j - 1].first : 0;
                int uxcnt = i - 1 >= 0 ? pcnt[i - 1][j].first : 0;
                int dluxcnt = (i - 1 >= 0 && j - 1 >= 0) ? pcnt[i - 1][j - 1].first : 0;
                int totalX = lxcnt + uxcnt - dluxcnt;
                totalX += (grid[i][j] == 'X' ? 1 : 0);
                int lycnt = j - 1 >= 0 ? pcnt[i][j - 1].second : 0;
                int uycnt = i - 1 >= 0 ? pcnt[i - 1][j].second : 0;
                int dluycnt = (i - 1 >= 0 && j - 1 >= 0) ? pcnt[i - 1][j - 1].second : 0;
                int totalY = lycnt + uycnt - dluycnt;
                totalY += (grid[i][j] == 'Y' ? 1 : 0);
                if (totalX && totalX == totalY) {
                    ans++;
                }
                pcnt[i][j].first = totalX;
                pcnt[i][j].second = totalY;
            }
        }
        return ans;
    }
};