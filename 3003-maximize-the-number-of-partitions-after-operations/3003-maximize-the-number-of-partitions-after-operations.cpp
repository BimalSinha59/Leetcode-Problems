class Solution {
public:
    long long f(int idx, int msk, int change, int k, string& s, int n,
                unordered_map<long long, int>& dp) {
        if (idx >= n) {
            return 1;
        }

        long long currmsk = (idx << 27) | (msk << 1) | (change);
        if (dp.count(currmsk) != 0) {
            return dp[currmsk];
        }

        int val = s[idx] - 'a';
        long long newmsk = (msk) | (1 << val);
        int scnt = __builtin_popcountll(newmsk);
        long long ans = 0, maxi = 0;
        if (scnt > k) {
            ans = 1 + f(idx + 1, (1 << val), change, k, s, n, dp);
            maxi = max(maxi, ans);
        } else {
            ans = f(idx + 1, newmsk, change, k, s, n, dp);
            maxi = max(maxi, ans);
        }

        if (change) {
            return dp[currmsk] = maxi;
        }

        for (int j = 0; j < 26; j++) {
            newmsk = (msk) | (1 << j);
            scnt = __builtin_popcountll(newmsk);
            if (scnt > k) {
                maxi = max(maxi, 1 + f(idx + 1, (1 << j), 1, k, s, n, dp));
            } else {
                maxi = max(maxi, f(idx + 1, newmsk, 1, k, s, n, dp));
            }
        }
        return dp[currmsk] = maxi;
    }
    int maxPartitionsAfterOperations(string s, int k) {
        int n = s.size();
        unordered_map<long long, int> dp;
        return (int)f(0, 0, 0, k, s, n, dp);
    }
};