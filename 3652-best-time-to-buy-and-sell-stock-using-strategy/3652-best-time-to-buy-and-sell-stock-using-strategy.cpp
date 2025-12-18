class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += 1LL * prices[i] * strategy[i];
        }
        long long fs = 0;
        for (int i = k / 2; i < k; i++) {
            fs += prices[i];
        }
        long long os = 0;
        for (int i = 0; i < k; i++) {
            os += 1LL * prices[i] * strategy[i];
        }
        long long ans = sum;
        ans = max(ans, fs + sum - os);
        for (int i = k; i < n; i++) {
            fs = fs - prices[i - k / 2] + prices[i];
            os = os - prices[i - k] * strategy[i - k] + prices[i] * strategy[i];
            long long ns = fs + sum - os;
            ans = max(ans, ns);
        }
        return ans;
    }
};
