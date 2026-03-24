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
                smul[i][j] = mul;
                mul = ((mul % MOD) * (grid[i][j] % MOD)) % MOD;
            }
        }
        long long left = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int right = smul[i][j];
                smul[i][j] = ((left % MOD) * (right % MOD)) % MOD;
                left = ((left % MOD) * (grid[i][j] % MOD)) % MOD;
            }
        }
        return smul;
    }
};