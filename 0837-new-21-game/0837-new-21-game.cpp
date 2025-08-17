class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> dp(n + 1);
        dp[0] = 1;
        double num;
        if (k > 0) {
            num = 1;
        } 
        else {
            num = 0;
        }

        for (int i = 1; i <= n; i++) {
            dp[i] = num / maxPts;
            if (i < k) {
                num += dp[i];
            }
            if (i - maxPts >= 0 && i - maxPts < k) {
                num -= dp[i - maxPts];
            }
        }
        double ans = 0;
        for (int i = k; i <= n; i++) {
            ans += dp[i];
        }
        return ans;
    }
};