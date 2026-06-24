class Solution {
public:
    const int MOD = 1e9 + 7;
    void matmul(vector<vector<int>>& C, const vector<vector<int>>& A, const vector<vector<int>>& B) {
        int len = A.size();
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                C[i][j] = 0;
                for (int k = 0; k < len; k++) {
                    C[i][j] = (C[i][j] + (1LL * A[i][k] * B[k][j]) % MOD) % MOD;
                }
            }
        }
    }
    
    int zigZagArrays(int n, int l, int r) {
        const int U = r - l; 
        if (U <= 0) return 0;

        vector<vector<int>> F(U, vector<int>(U, 0));
        vector<vector<int>> G(U, vector<int>(U, 0));
        vector<vector<int>> H(U, vector<int>(U, 0));

        for (int i = 0; i < U; i++) {
            F[i][i] = 1;
            H[i][i] = 1;
            for (int j = 0; j <= i; j++) {
                G[i][U - 1 - j] = 1;
            }
        }

        for (int p = 1; p <= n; p <<= 1) {
            if (p > 1) {
                matmul(H, G, G);
                swap(G, H);
            }
            if ((n & p) != 0) {
                matmul(H, F, G);
                swap(F, H);
            }
        }

        int sum = 0;
        for (int k = 0; k < U; k++) {
            sum = (sum + F[U - 1][k]) % MOD;
        }

        return (1LL * sum << 1) % MOD;
    }
};