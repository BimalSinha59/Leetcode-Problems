class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        int n = nums.size();
        long long ans = 0;
        int i = 0;
        long long sum = 0;
        int mini = 1e9;
        while (i < n) {
            while (i < n && s[i] == '1') {
                sum += nums[i];
                if (mini != 1e9) {
                    mini = min(mini, nums[i]);
                }
                i++;
            }
            ans += sum;
            sum = 0;
            ans -= mini == 1e9 ? 0 : mini;
            if (i < n) {
                mini = nums[i];
                sum = nums[i];
            }
            i++;
        }
        return ans;
    }
};