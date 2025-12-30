class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                bool f1 = true, f2 = true, f3 = true;
                int lsum = -1;
                int cnt = 0;
                unordered_set<int> st;
                for (int k = i - 1; k <= i + 1 && k < n; k++) {
                    int sum = 0;
                    for (int l = j - 1; l <= j + 1 && l < m; l++) {
                        if (grid[k][l] <= 0 || grid[k][l] > 9 || st.count(grid[k][l])) {
                            f1 = false;
                            break;
                        }
                        st.insert(grid[k][l]);
                        sum += grid[k][l];
                        cnt++;
                        if (k == i - 1) {
                            lsum = sum;
                        }
                    }
                    if (sum != lsum || !f1) {
                        f1 = false;
                        break;
                    }
                }
                if (cnt != 9) {
                    f1 = false;
                }
                if (f1) {
                    cnt = 0;
                    for (int l = j - 1; l <= j + 1 && l < m; l++) {
                        int sum = 0;
                        for (int k = i - 1; k <= i + 1 && k < n; k++) {
                            sum += grid[k][l];
                            cnt++;
                        }
                        if (sum != lsum) {
                            f2 = false;
                            break;
                        }
                    }
                    if (cnt != 9) {
                        f2 = false;
                    }
                }
                int ds1 = grid[i - 1][j - 1] + grid[i][j] + grid[i + 1][j + 1];
                int ds2 = grid[i + 1][j - 1] + grid[i][j] + grid[i - 1][j + 1];
                if (!f1 || !f2 || ds1 != lsum || ds2 != lsum) {
                    f3 = false;
                }
                if (f1 && f2 && f3) {
                    ans++;
                }
            }
        }
        return ans;
    }
};