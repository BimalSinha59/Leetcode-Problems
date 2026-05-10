class Solution {
public:
    int solve(int i, int n, vector<int>& nums, int target, vector<int>& dp) {
        if (i == n - 1) {
            return 0;
        }
        if (i >= n) {
            return INT_MIN;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        int ans = INT_MIN;
        for (int j = i + 1; j < n; j++) {
            int diff = nums[j] - nums[i];
            if (-target <= diff && diff <= target) {
                ans = max(ans, 1 + solve(j, n, nums, target, dp));
            }
        }
        return dp[i] = ans;
    }
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, -1);
        int ans = solve(0, n, nums, target, dp);
        return (ans < -1e4 ? -1 : ans);
    }
};