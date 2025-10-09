class Solution {
public:
    int sumOfGoodSubsequences(vector<int>& nums) {
        int mod = 1e9 + 7;
        int maxi = 1e5 + 1;
        vector<int> dp(maxi, 0), sum(maxi, 0);
        for (auto num : nums) {
            dp[num] = (dp[num] + 1) % mod;
            sum[num] = (sum[num] + num) % mod;
            if (num - 1 >= 0) {
                dp[num] = (dp[num] + dp[num - 1]) % mod;
                sum[num] = (sum[num] + sum[num - 1] +
                           (num * 1LL * dp[num - 1]) % mod) % mod;
            }
            if (num + 1 < maxi) {
                dp[num] = (dp[num] + dp[num + 1]) % mod;
                sum[num] = (sum[num] + sum[num + 1] +
                           (num * 1LL * dp[num + 1]) % mod) % mod;
            }
        }
        int ans = 0;
        for (auto it : sum) {
            ans = (ans * 1LL + it) % mod;
        }
        return ans;
    }
};