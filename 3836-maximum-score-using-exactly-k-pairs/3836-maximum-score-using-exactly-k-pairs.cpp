class Solution {
public:
    long long solve(int idx1, int idx2, int k, vector<int>& nums1,
                    vector<int>& nums2, vector<vector<vector<long long>>>& dp) {
        if (k == 0)
            return 0;
        if (idx1 == nums1.size() || idx2 == nums2.size()) {
            return -1e15;
        }
        if (dp[idx1][idx2][k] != -1e16) {
            return dp[idx1][idx2][k];
        }
        long long ans1 = (long long)nums1[idx1] * nums2[idx2] +
                         solve(idx1 + 1, idx2 + 1, k - 1, nums1, nums2, dp);
        long long ans2 = solve(idx1 + 1, idx2, k, nums1, nums2, dp);
        long long ans3 = solve(idx1, idx2 + 1, k, nums1, nums2, dp);

        return dp[idx1][idx2][k] = max({ans1, ans2, ans3});
    }

    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<vector<long long>>> dp(
            n, vector<vector<long long>>(m, vector<long long>(k + 1, -1e16)));
        return solve(0, 0, k, nums1, nums2, dp);
    }
};