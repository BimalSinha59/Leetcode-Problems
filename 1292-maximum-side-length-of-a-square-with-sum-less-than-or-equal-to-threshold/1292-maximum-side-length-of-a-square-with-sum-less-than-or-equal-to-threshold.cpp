class Solution {
public:
    bool isSquarePossible(int i, int j, int side, int& n, int& m,
                          vector<vector<int>>& psum, int& threshold) {
                            
        int sum = psum[i][j];
        if (j - side >= 0) {
            sum -= psum[i][j - side];
        }
        if (i - side >= 0) {
            sum -= psum[i - side][j];
        }
        if (i - side >= 0 && j - side >= 0) {
            sum += psum[i - side][j - side];
        }
        return sum <= threshold;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> psum(n, vector<int>(m, 0));
        psum[0][0] = mat[0][0];
        for (int i = 1; i < n; i++) {
            psum[i][0] = psum[i - 1][0] + mat[i][0];
        }
        for (int j = 1; j < m; j++) {
            psum[0][j] = psum[0][j - 1] + mat[0][j];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                psum[i][j] = mat[i][j] + psum[i - 1][j] + psum[i][j - 1] -
                             psum[i - 1][j - 1];
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int s = ans, e = min(i + 1, j + 1);
                int maxi = 0;
                while (s <= e) {
                    int mid = (s + e) / 2;
                    if (isSquarePossible(i, j, mid, n, m, psum, threshold)) {
                        maxi = mid;
                        s = mid + 1;
                    } else {
                        e = mid - 1;
                    }
                }
                ans = max(ans, maxi);
            }
        }
        return ans;
    }
};