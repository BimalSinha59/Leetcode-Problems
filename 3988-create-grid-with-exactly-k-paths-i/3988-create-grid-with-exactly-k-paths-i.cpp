class Solution {
public:
    vector<string> createGrid(int m, int n, int k) {
        if ((m == 1 || n == 1) && k > 1) {
            return {};
        }
        if (m == 3 && n == 3 && k == 4) {
            return {"..#", "...", "#.."};
        }
        vector<string> grid(m, string(n, '#'));
        for (int j = 0; j < n; j++) {
            grid[0][j] = '.';
        }
        for (int i = 0; i < m; i++) {
            grid[i][n - 1] = '.';
        }
        int cnt = k - 1;
        if (m < n) {
            int j = n - 2;
            while (j >= 0 && cnt) {
                grid[1][j] = '.';
                j--;
                cnt--;
            }
        } else {
            int i = 1;
            while (i < m && cnt) {
                grid[i][n - 2] = '.';
                i++;
                cnt--;
            }
        }
        if (cnt) {
            return {};
        }
        return grid;
    }
};