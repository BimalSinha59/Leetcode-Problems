class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        int n = prices.size();
        long long x = 1;
        for (int i = 1; i < n; i++) {
            if (prices[i - 1] == prices[i] + 1) {
                x++;
            } else {
                ans += (x * (x + 1)) / 2;
                x = 1;
            }
        }
        ans += (x * (x + 1)) / 2;
        return ans;
    }
};