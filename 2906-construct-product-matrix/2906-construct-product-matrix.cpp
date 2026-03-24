class Solution {
public:
    const int MOD = 12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> pmul(n, vector<int>(m, 0));
        vector<vector<int>> smul(n, vector<int>(m, 0));
        long long mul1 = 1, mul2 = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mul1 = ((mul1 % MOD) * (grid[i][j] % MOD)) % MOD;
                mul2 = ((mul2 % MOD) * (grid[n - 1 - i][m - 1 - j] % MOD)) % MOD;
                pmul[i][j] = mul1;
                smul[n - 1 - i][m - 1 - j] = mul2;
            }
        }
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int left = 1;
                if (j == 0 && i != 0) {
                    left = pmul[i - 1][m - 1];
                } else if (j != 0) {
                    left = pmul[i][j - 1];
                }
                int right = 1;
                if (j == m - 1 && i != n - 1) {
                    right = smul[i + 1][0];
                } else if (j != m - 1) {
                    right = smul[i][j + 1];
                }
                ans[i][j] = ((left % MOD) * (right % MOD)) % MOD;
            }
        }
        return ans;
    }
};