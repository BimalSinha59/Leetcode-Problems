class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int lsum = 0, rsum = 0;
        int ans = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            lsum += nums[i];
            rsum = sum - lsum;
            if ((abs(lsum - rsum)) % 2 == 0) {
                ans++;
            }
        }
        return ans;
    }
};