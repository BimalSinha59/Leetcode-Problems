class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size();
        int m = boxGrid[0].size();
        vector<vector<char>> ans(m, vector<char>(n, '.'));
        for (int i = n - 1; i >= 0; i--) {
            int j = m - 1;
            while (j >= 0 && boxGrid[i][j] != '.') {
                ans[j][n - i - 1] = boxGrid[i][j];
                j--;
            }
            int k = j - 1;
            while (k >= 0) {
                if (boxGrid[i][k] == '#' && boxGrid[i][j] == '.') {
                    ans[j][n - i - 1] = '#';
                    boxGrid[i][j] = '#';
                    boxGrid[i][k] = '.';
                    while (j >= 0 && boxGrid[i][j] != '.') {
                        ans[j][n - i - 1] = boxGrid[i][j];
                        j--;
                    }
                } else {
                    if (boxGrid[i][k] == '*') {
                        j = k;
                    } else if (boxGrid[i][k] == '.' && boxGrid[i][j] != '.') {
                        j = k;
                    }
                    ans[k][n - i - 1] = boxGrid[i][k];
                }
                k--;
            }
        }
        return ans;
    }
};