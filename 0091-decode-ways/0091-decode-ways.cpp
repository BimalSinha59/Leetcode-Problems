class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') {
            return 0;
        }
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1, dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            int odig = s[i - 1] - '0';
            if (odig != 0) {
                dp[i] += dp[i - 1];
            }
            string str = s.substr(i - 2, 2);
            int tdig = stoi(str);
            if (tdig >= 10 && tdig <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};