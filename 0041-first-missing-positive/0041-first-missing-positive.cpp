class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (nums[i] <= 0) {
                nums[i] = n;
            }
        }
        for (int i = 0; i < n; i++) {
            if (abs(nums[i]) < n && nums[abs(nums[i])] > 0) {
                nums[abs(nums[i])] *= -1;
            }
        }
        for (int i = 1; i < n; i++) {
            if (nums[i] > 0) {
                return i;
            }
        }
        if (sum == (n * 1LL * (n + 1)) / 2) {
            return n + 1;
        }
        return n;
    }
};