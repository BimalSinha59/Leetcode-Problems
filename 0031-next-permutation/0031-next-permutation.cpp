class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int breakIdx = -1;
        for (int i = n - 2; i > 0; i--) {
            if (nums[i] < nums[i + 1]) {
                breakIdx = i;
                break;
            }
        }
        if (breakIdx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] > nums[breakIdx]) {
                swap(nums[i], nums[breakIdx]);
            }
        }
        reverse(nums.begin() + breakIdx + 1, nums.end());
    }
};