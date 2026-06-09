class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for (int& num : nums) {
            mini = min(mini, num);
            maxi = max(maxi, num);
        }
        long long ans = 1LL * k * (maxi - mini);
        return ans;
    }
};