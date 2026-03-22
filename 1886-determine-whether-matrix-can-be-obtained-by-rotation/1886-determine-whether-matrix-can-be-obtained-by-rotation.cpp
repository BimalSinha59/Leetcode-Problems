class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        bool f1 = true, f2 = true, f3 = true, f4 = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] != target[i][j]) {
                    f1 = false;
                }
                if (mat[i][j] != target[j][n - i - 1]) {
                    f2 = false;
                }
                if (mat[i][j] != target[n - i - 1][n - j - 1]) {
                    f3 = false;
                }
                if (mat[i][j] != target[n - j - 1][i]) {
                    f4 = false;
                }
            }
        }
        return f1 | f2 | f3 | f4;
    }
};