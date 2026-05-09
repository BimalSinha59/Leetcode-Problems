class Solution {
public:
    void rotateByK(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        vector<int> temp;
        for (int i = 0; i < k; i++) {
            temp.push_back(nums[i]);
        }
        for (int i = k; i < n; i++) {
            nums[i - k] = nums[i];
        }
        for (int i = 0; i < k; i++) {
            nums[n - k + i] = temp[i];
        }
    }
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int d = 0;
        while (d < min(n, m) / 2) {
            vector<int> temp;
            for (int j = d; j < m - d; j++) {
                temp.push_back(grid[d][j]);
            }
            for (int i = d + 1; i < n - d; i++) {
                temp.push_back(grid[i][m - 1 - d]);
            }
            for (int j = m - d - 2; j >= d; j--) {
                temp.push_back(grid[n - 1 - d][j]);
            }
            for (int i = n - d - 2; i > d; i--) {
                temp.push_back(grid[i][d]);
            }
            rotateByK(temp, k);
            int idx = 0;
            for (int j = d; j < m - d; j++) {
                grid[d][j] = temp[idx];
                idx++;
            }
            for (int i = d + 1; i < n - d; i++) {
                grid[i][m - 1 - d] = temp[idx];
                idx++;
            }
            for (int j = m - d - 2; j >= d; j--) {
                grid[n - 1 - d][j] = temp[idx];
                idx++;
            }
            for (int i = n - d - 2; i > d; i--) {
                grid[i][d] = temp[idx];
                idx++;
            }
            d++;
        }
        return grid;
    }
};