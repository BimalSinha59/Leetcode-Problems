class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int x = i - k, y = i + k;
            if (x < 0 && y >= n) {
                sum += nums[i];
            } else if (x < 0 && y < n) {
                if (nums[i] > nums[y])
                    sum += nums[i];
            } else if (x >= 0 && y >= n) {
                if (nums[i] > nums[x])
                    sum += nums[i];
            } else {
                if (nums[i] > nums[x] && nums[i] > nums[y])
                    sum += nums[i];
            }
        }
        return sum;
    }
};