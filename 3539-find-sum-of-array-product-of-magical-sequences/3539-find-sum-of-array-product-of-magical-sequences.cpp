static constexpr int md = 1e9 + 7;
static int C[31][31] = {{0}};
static int dp[31][31][50][31];
class Solution {
    int m, k, n;
    void pscl() {
        if (C[0][0] == 1)
            return; 
        for (int i = 1; i <= 30; i++) {
            C[i][0] = C[i][i] = 1;
            for (int j = 1; j <= i / 2; j++) {
                const int Cij = C[i - 1][j - 1] + C[i - 1][j];
                C[i][j] = C[i][i - j] = Cij;
            }
        }
    }

    int dfs(int m, int k, int i, unsigned flg, vector<int>& nums) {
        const int bz = popcount(flg);
        if (m < 0 || k < 0 || m + bz < k)
            return 0;
        if (m == 0)
            return (k == bz) ? 1 : 0;
        if (i >= n)
            return 0;

        if (dp[m][k][i][flg] != -1){
            return dp[m][k][i][flg];
        }

        long long ans = 0, powX = 1;
        const int x = nums[i];
        for (int f = 0; f <= m; f++) {
            long long perm = C[m][f] * powX % md;

            unsigned nwflg = flg + f;
            unsigned nxflg = nwflg >> 1;
            bool bitSet = nwflg & 1;

            ans = (ans + perm * dfs(m - f, k - bitSet, i + 1, nxflg, nums)) % md;
            powX = (powX * x) % md;
        }
        return dp[m][k][i][flg] = ans;
    }

public:
    int magicalSum(int m, int k, vector<int>& nums) {
        pscl();
        this->m = m;
        this->k = k;
        n = nums.size();
        for (int i = 0; i <= m; i++){
            for (int j = 0; j <= m; j++){
                for (int s = 0; s < n; s++){
                    memset(dp[i][j][s], -1, sizeof(int) * (m + 1));
                }
            }
        }
        return dfs(m, k, 0, 0, nums);
    }
};
