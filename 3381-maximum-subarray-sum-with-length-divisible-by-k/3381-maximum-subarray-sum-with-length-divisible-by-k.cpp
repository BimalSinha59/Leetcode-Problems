class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long psum = 0;
        long long mxsum = -1e18;
        vector<long long> ks(k, 1e18);
        ks[k - 1] = 0;
        for (int i = 0; i < n; i++) {
            psum += nums[i];
            mxsum = max(mxsum, psum - ks[i % k]);
            ks[i % k] = min(ks[i % k], psum);
        }
        return mxsum;
    }
};