class Solution {
public:
    bool isInc(int idx, int k, vector<int>& nums) {
        int n = nums.size();
        if (n - idx < k) {
            return false;
        }
        for (int i = idx + 1; i < idx + k && i < n; i++) {
            if (nums[i - 1] >= nums[i]) {
                return false;
            }
        }
        return true;
    }
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; i < n - k; i++) {
            if (isInc(i, k, nums) && isInc(i + k, k, nums)) {
                return true;
            }
        }
        return false;
    }
};