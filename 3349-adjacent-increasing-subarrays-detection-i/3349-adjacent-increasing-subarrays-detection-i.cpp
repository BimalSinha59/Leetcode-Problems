class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0, cnt = 1, pcnt = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] < nums[i]) {
                cnt++;
            } 
            else {
                pcnt = cnt;
                cnt = 1;
            }
            ans = max(ans, min(cnt, pcnt));
            ans = max(ans, cnt / 2);
        }
        return ans >= k;
    }
};