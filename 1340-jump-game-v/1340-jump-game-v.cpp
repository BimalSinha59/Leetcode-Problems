class Solution {
public:
    int dfs(int i, int d, int n, vector<int>& arr, vector<int>& dp) {
        if (dp[i] != -1) {
            return dp[i];
        }
        int ans = 1;
        for (int j = i - 1; abs(i - j) <= d && j >= 0 && arr[j] < arr[i]; j--) {
            ans = max(ans, 1 + dfs(j, d, n, arr, dp));
        }
        for (int j = i + 1; abs(i - j) <= d && j < n && arr[j] < arr[i]; j++) {
            ans = max(ans, 1 + dfs(j, d, n, arr, dp));
        }
        return dp[i] = ans;
    }
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        int res = 1;
        vector<int> dp(n, -1);
        for (int i = 0; i < n; i++) {
            res = max(res, dfs(i, d, n, arr, dp));
        }
        return res;
    }
};