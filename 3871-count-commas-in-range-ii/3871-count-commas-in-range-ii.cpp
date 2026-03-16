class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        for (long long num = 1000; num <= n; num *= 1000) {
            ans += (n - num + 1);
        }
        return ans;
    }
};