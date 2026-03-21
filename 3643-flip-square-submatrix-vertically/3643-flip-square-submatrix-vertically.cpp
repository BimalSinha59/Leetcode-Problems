class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for (int j = y; j < y + k; j++) {
            int l = x, r = x + k - 1;
            while (l < r) {
                swap(grid[l][j], grid[r][j]);
                l++;
                r--;
            }
        }
        return grid;
    }
};