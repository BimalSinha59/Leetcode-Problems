class Solution {
public:
    long long solve(int i, int trend, vector<int>& nums, int n,
                    vector<vector<long long>>& dp) {
                        
        if (i == n) {
            if (trend == 3) {
                return 0;
            } else {
                return -1e18;
            }
        }

        if (dp[i][trend] != LLONG_MIN) {
            return dp[i][trend];
        }

        long long take = -1e18;
        long long skip = -1e18;
        if (trend == 0) {
            skip = solve(i + 1, 0, nums, n, dp);
        }

        if (trend == 3) {
            take = nums[i];
        }

        if (i + 1 < n) {
            int curr = nums[i];
            int next = nums[i + 1];

            if (trend == 0 && next > curr) {
                take = max(take, curr + solve(i + 1, 1, nums, n, dp));
            } else if (trend == 1) {
                if (next > curr) {
                    take = max(take, curr + solve(i + 1, 1, nums, n, dp));
                } else if (next < curr) {
                    take = max(take, curr + solve(i + 1, 2, nums, n, dp));
                }
            } else if (trend == 2) {
                if (next < curr) {
                    take = max(take, curr + solve(i + 1, 2, nums, n, dp));
                } else if (next > curr) {
                    take = max(take, curr + solve(i + 1, 3, nums, n, dp));
                }
            } else if (trend == 3 && next > curr) {
                take = max(take, curr + solve(i + 1, 3, nums, n, dp));
            }
        }

        return dp[i][trend] = max(take, skip);
    }

    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();

        vector<vector<long long>> dp(n + 1, vector<long long>(4, LLONG_MIN));

        return solve(0, 0, nums, n, dp);
    }
};
