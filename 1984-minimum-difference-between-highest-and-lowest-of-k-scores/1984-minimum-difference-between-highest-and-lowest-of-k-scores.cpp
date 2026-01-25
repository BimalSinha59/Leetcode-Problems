class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.rbegin(), nums.rend());
        int n = nums.size();
        int ans = 1e9;
        for (int i = 0; k - 1 + i < n; i++) {
            ans = min(ans, nums[i] - nums[k - 1 + i]);
        }
        return ans;
    }
};