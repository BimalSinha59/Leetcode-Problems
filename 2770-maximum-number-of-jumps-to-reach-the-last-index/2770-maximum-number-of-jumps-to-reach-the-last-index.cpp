class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, INT_MIN);
        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            int ans = INT_MIN;
            for (int j = 0; j < i; j++) {
                if (abs(nums[j] - nums[i]) <= target) {
                    ans = max(ans, dp[j] + 1);
                }
            }
            dp[i] = ans;
        }
        return (dp[n - 1] < 0 ? -1 : dp[n - 1]);
    }
};