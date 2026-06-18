class Solution {
public:
    bool subsetSumEqualtoTarget(int idx, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if (idx < 0) {
            return false;
        }
        if (idx == 0) {
            return nums[0] == target;
        }
        if (dp[idx][target] != -1) {
            return dp[idx][target];
        }
        bool not_take = subsetSumEqualtoTarget(idx - 1, target, nums, dp);
        bool take = false;
        if (target >= nums[idx]) {
            take =
                subsetSumEqualtoTarget(idx - 1, target - nums[idx], nums, dp);
        }
        return dp[idx][target] = not_take | take;
    }
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (int& num : nums) {
            totalSum += num;
        }
        if (totalSum % 2 != 0) {
            return false;
        }
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(totalSum / 2 + 1, -1));
        return subsetSumEqualtoTarget(n - 1, totalSum / 2, nums, dp);
    }
};