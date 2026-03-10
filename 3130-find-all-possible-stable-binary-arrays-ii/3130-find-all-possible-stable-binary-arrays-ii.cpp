class Solution {
public:
    int mod = 1e9 + 7;
    int lmt;

    int solve(int zero, int one, int lastBit, vector<vector<vector<int>>>& dp) {
        if (zero == 0) {
            return (lastBit == 0 || one > lmt) ? 0 : 1;
        } else if (one == 0) {
            return (lastBit == 1 || zero > lmt) ? 0 : 1;
        }

        if (dp[zero][one][lastBit] == -1) {
            int res = 0;
            if (lastBit == 0) {
                res = (solve(zero - 1, one, 0, dp) +
                       solve(zero - 1, one, 1, dp)) %
                      mod;
                if (zero > lmt) {
                    res = (res - solve(zero - lmt - 1, one, 1, dp) + mod) % mod;
                }
            } else {
                res = (solve(zero, one - 1, 0, dp) +
                       solve(zero, one - 1, 1, dp)) %
                      mod;
                if (one > lmt) {
                    res = (res - solve(zero, one - lmt - 1, 0, dp) + mod) % mod;
                }
            }
            dp[zero][one][lastBit] = res % mod;
        }
        return dp[zero][one][lastBit];
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        lmt = limit;
        vector<vector<vector<int>>> dp(
            zero + 1, vector<vector<int>>(one + 1, vector<int>(2, -1)));
        return (solve(zero, one, 0, dp) + solve(zero, one, 1, dp)) % mod;
    }
};