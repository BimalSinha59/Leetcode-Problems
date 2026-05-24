class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<pair<int, int>> ele_idx_pair;
        for (int i = 0; i < n; i++) {
            ele_idx_pair.push_back({arr[i], i});
        }
        sort(ele_idx_pair.begin(), ele_idx_pair.end());
        int res = 1;
        vector<int> dp(n, 1);
        for (auto& p : ele_idx_pair) {
            int i = p.second;
            int ans = 1;
            for (int j = i - 1; abs(i - j) <= d && j >= 0 && arr[j] < arr[i];
                 j--) {
                ans = max(ans, 1 + dp[j]);
            }
            for (int j = i + 1; abs(i - j) <= d && j < n && arr[j] < arr[i];
                 j++) {
                ans = max(ans, 1 + dp[j]);
            }
            dp[i] = ans;
            res = max(res, dp[i]);
        }
        return res;
    }
};