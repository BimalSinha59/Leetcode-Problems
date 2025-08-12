class Solution {
public:
    int mod = 1e9 + 7;
    int f(int idx, vector<int>& v, int tar, vector<vector<int>>& dp) {
        if (tar == 0) {
            return 1;
        }
        if (idx >= v.size()) {
            return 0;
        }
        if (dp[idx][tar] != -1) {
            return dp[idx][tar];
        }
        int take = 0;
        if (v[idx] <= tar) {
            take = f(idx + 1, v, tar - v[idx], dp);
        }
        int ntake = f(idx + 1, v, tar, dp);
        return dp[idx][tar] = (take + ntake) % mod;
    }
    int numberOfWays(int n, int x) {
        vector<int> v;
        for (int i = 1; i <= n; i++) {
            int num = pow(i, x);
            if (num <= n) {
                v.push_back(num);
            } else {
                break;
            }
        }
        int m = v.size();
        vector<vector<int>> dp(m, vector<int>(n + 1, -1));
        return f(0, v, n, dp);
    }
};