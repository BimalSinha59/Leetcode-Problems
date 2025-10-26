class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            nums[i] = abs(nums[i]);
        }
        sort(nums.begin(), nums.end());
        long long sum = 0;
        long long hsum = 0;
        for (int i = 0; i < n; i++) {
            sum += (nums[i] * nums[i]);
            if (i >= n / 2) {
                hsum += (nums[i] * nums[i]);
            }
        }
        return hsum - (sum - hsum);
    }
};