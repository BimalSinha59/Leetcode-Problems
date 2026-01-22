class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        int lastEle = nums[0];
        int currSum = 0;
        int i = 1;
        int ans = 0;
        while (i < n) {
            currSum += nums[i];
            if (currSum >= lastEle) {
                lastEle = currSum;
                currSum = 0;
            } else {
                ans++;
            }
            i++;
        }
        return ans;
    }
};