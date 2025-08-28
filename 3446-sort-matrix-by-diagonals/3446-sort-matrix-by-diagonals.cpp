class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for (int i = n - 1; i >= 0; i--) {
            vector<int> v;
            int r = i;
            for (int c = 0; c < m; c++) {
                if (r < n && c < m) {
                    v.push_back(grid[r][c]);
                } 
                else {
                    break;
                }
                r++;
            }
            sort(v.rbegin(), v.rend());
            r = i;
            for (int c = 0; c < m; c++) {
                if (r < n && c < m) {
                    grid[r][c] = v[c];
                } 
                else {
                    break;
                }
                r++;
            }
        }
        for (int j = 1; j < m; j++) {
            vector<int> v;
            int c = j;
            for (int r = 0; r < n; r++) {
                if (r < n && c < m) {
                    v.push_back(grid[r][c]);
                } 
                else {
                    break;
                }
                c++;
            }
            sort(v.begin(), v.end());
            c = j;
            for (int r = 0; r < n; r++) {
                if (r < n && c < m) {
                    grid[r][c] = v[r];
                } 
                else {
                    break;
                }
                c++;
            }
        }
        return grid;
    }
};