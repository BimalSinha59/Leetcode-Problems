class Solution {
public:
    const int mod = 1e9 + 7;
    long long compute20Pow(long long x, long long n) {
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return x;
        }
        if (n % 2 == 0) {
            return compute20Pow(x * x % mod, n / 2) % mod;
        }
        return ((compute20Pow(x, n - 1) % mod) * x) % mod;
    }
    int countGoodNumbers(long long n) {
        if (n % 2 == 0) {
            return compute20Pow(20, n / 2) % mod;
        }
        return ((compute20Pow(20, (n - 1) / 2) % mod) * 5) % mod;
    }
};