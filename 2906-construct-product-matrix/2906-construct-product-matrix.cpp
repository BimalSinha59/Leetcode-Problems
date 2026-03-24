class Solution {
public:
    const int MOD = 12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> smul(n, vector<int>(m, 0));
        long long mul = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                mul = ((mul % MOD) * (grid[i][j] % MOD)) % MOD;
                smul[i][j] = mul;
            }
        }
        vector<vector<int>> ans(n, vector<int>(m, 0));
        long long left = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int right = j + 1 == m ? (i + 1 == n ? 1 : smul[i + 1][0]) : smul[i][j + 1];
                ans[i][j] = ((left % MOD) * (right % MOD)) % MOD;
                left = ((left % MOD) * (grid[i][j] % MOD)) % MOD;
            }
        }
        return ans;
    }
};