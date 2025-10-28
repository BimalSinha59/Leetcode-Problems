class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int& num : nums) {
            sum += num;
        }
        int lsum = 0, rsum = sum;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (lsum - rsum >= 0 && lsum - rsum <= 1) {
                    ans++;
                }
                if (rsum - lsum >= 0 && rsum - lsum <= 1) {
                    ans++;
                }
            } else {
                lsum += nums[i];
                rsum -= nums[i];
            }
        }
        return ans;
    }
};