class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> ans;
        int r = 0, c = 0;
        while (ans.size() != m * n) {
            for (int i = r, j = c;; i--, j++) {
                if (i < 0 || j >= m) {
                    r = i + 1;
                    c = j;
                    break;
                }
                if (i >= 0 && i < n && j >= 0 && j < m) {
                    ans.push_back(mat[i][j]);
                }
            }
            for (int i = r, j = c;; i++, j--) {
                if (i >= n || j < 0) {
                    r = i;
                    c = j + 1;
                    break;
                }
                if (i >= 0 && i < n && j >= 0 && j < m) {
                    ans.push_back(mat[i][j]);
                }
            }
        }
        return ans;
    }
};