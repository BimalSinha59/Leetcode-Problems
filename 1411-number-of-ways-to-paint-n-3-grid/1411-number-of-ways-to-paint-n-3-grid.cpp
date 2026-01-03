class Solution {
public:
    int numOfWays(int n) {
        int mod = 1e9 + 7;
        long long x = 6, y = 6;
        for (int i = 2; i <= n; i++) {
            long long nx = (2 * x + 2 * y) % mod;
            long long ny = (2 * x + 3 * y) % mod;
            x = nx;
            y = ny;
        }
        int ans = (x + y) % mod;
        return ans;
    }
};