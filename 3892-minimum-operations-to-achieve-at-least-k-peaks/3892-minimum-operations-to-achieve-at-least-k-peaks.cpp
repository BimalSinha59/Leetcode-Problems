class Solution {
public:
    vector<int> costs;
    vector<vector<int>> dp;
    int solve(int i, int cnt, int n, int k) {
        if (cnt == k) {
            return 0;
        }
        if (i >= n) {
            return 1e9;
        }
        if (dp[i][cnt] != -1) {
            return dp[i][cnt];
        }
        int ans1 = costs[i] + solve(i + 2, cnt + 1, n, k);
        int ans2 = solve(i + 1, cnt, n, k);
        return dp[i][cnt] = min(ans1, ans2);
    }
    int minOperations(vector<int>& nums, int k) {
        if (k == 0)
            return 0;
        int n = nums.size();
        if (k > n / 2) {
            return -1;
        }
        costs.resize(n, 0);
        for (int i = 0; i < n; i++) {
            int left = i - 1 >= 0 ? nums[i - 1] : nums[n - 1];
            int right = i + 1 < n ? nums[i + 1] : nums[0];
            int cost = max(left, right) + 1 - nums[i];
            costs[i] = cost < 0 ? 0 : cost;
        }
        dp.assign(n, vector<int>(k + 1, -1));
        int res1 = solve(1, 0, n, k);
        dp.assign(n, vector<int>(k + 1, -1));
        int res2 = 1e9;
        if (n >= 3) {
            res2 = costs[0] + solve(2, 1, n - 1, k);
        } else if (k == 1) {
            res2 = costs[0];
        }
        return min(res1, res2);
    }
};