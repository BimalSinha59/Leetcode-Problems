class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int x = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            x += i * nums[i];
        }
        int ans = x;
        for (int k = 1; k < n; k++) {
            x = x + sum - n * nums[n - k];
            ans = max(ans, x);
        }
        return ans;
    }
};