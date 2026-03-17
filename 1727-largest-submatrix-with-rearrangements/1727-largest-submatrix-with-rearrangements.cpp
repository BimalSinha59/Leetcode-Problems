class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ones(m, 0);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j]) {
                    ones[j]++;
                } else {
                    ones[j] = 0;
                }
            }
            vector<int> temp = ones;
            sort(temp.begin(), temp.end());
            for (int j = 0; j < m; j++) {
                ans = max(ans, (m - j) * temp[j]);
            }
        }
        return ans;
    }
};