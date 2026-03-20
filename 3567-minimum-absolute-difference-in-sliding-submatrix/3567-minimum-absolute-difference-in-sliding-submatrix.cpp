class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans(n - k + 1, vector<int>(m - k + 1));
        for (int i = 0; i <= n - k; i++) {
            for (int j = 0; j <= m - k; j++) {
                vector<int> temp;
                for (int ii = i; ii < i + k; ii++) {
                    for (int jj = j; jj < j + k; jj++) {
                        temp.push_back(grid[ii][jj]);
                    }
                }
                sort(temp.begin(), temp.end());
                int minDiff = 1e9;
                for (int l = 1; l < k * k; l++) {
                    if (temp[l] != temp[l - 1]) {
                        minDiff = min(minDiff, temp[l] - temp[l - 1]);
                    }
                }
                ans[i][j] = (minDiff == 1e9 ? 0 : minDiff);
            }
        }
        return ans;
    }
};