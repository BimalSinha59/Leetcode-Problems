class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        long long mod = 1e9 + 7;
        vector<long long> dp(n + 1);
        vector<long long> psum(n + 1);
        deque<int> mnq, mxq;

        dp[0] = 1;
        psum[0] = 1;
        for (int i = 0, j = 0; i < n; i++) {
            while (!mxq.empty() && nums[mxq.back()] <= nums[i]) {
                mxq.pop_back();
            }
            mxq.push_back(i);
            while (!mnq.empty() && nums[mnq.back()] >= nums[i]) {
                mnq.pop_back();
            }
            mnq.push_back(i);
            while (!mxq.empty() && !mnq.empty() &&
                   nums[mxq.front()] - nums[mnq.front()] > k) {
                if (mxq.front() == j) {
                    mxq.pop_front();
                }
                if (mnq.front() == j) {
                    mnq.pop_front();
                }
                j++;
            }

            dp[i + 1] = (psum[i] - (j > 0 ? psum[j - 1] : 0) + mod) % mod;
            psum[i + 1] = (psum[i] + dp[i + 1]) % mod;
        }

        return dp[n];
    }
};