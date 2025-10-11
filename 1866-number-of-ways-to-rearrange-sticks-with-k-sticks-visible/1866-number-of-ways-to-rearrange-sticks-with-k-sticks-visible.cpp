class Solution {
public:
    int f(int n, int k, vector<vector<int>>& dp, int& mod) {
        if (n == k) {
            return 1;
        }
        if (k == 0) {
            return 0;
        }
        if (dp[n][k] != -1) {
            return dp[n][k];
        }
        long long ans1 = f(n - 1, k - 1, dp, mod) % mod;
        long long ans2 = f(n - 1, k, dp, mod) * 1LL * (n - 1) % mod;
        return dp[n][k] = (int)(ans1 + ans2) % mod;
    }
    int rearrangeSticks(int n, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        int mod = 1e9 + 7;
        return f(n, k, dp, mod);
    }
};