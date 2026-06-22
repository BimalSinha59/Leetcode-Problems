class Solution {
public:
    const int MOD = 1e9 + 7;
    long long canPossible(vector<int>& value, vector<int>& decay, long long mid, int& n) {
        long long res = 0;
        for (int i = 0; i < n; i++) {
            if (value[i] < mid) {
                continue;
            }
            res += (value[i] - mid) / decay[i] + 1;
            if (res > 1e9) {
                return res;
            }
        }
        return res;
    }
    int maxTotalValue(vector<int>& value, vector<int>& decay, int m) {
        int n = value.size();
        long long low = 0, high = 1e18;
        while (low < high) {
            long long mid = (low + high + 1) / 2;
            if (canPossible(value, decay, mid, n) >= m) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        long long res = 0, take = 0;
        for (int i = 0; i < n; i++) {
            if (value[i] < low) {
                continue;
            }
            long long t = (value[i] - low) / decay[i] + 1;
            long long s = t * value[i] - decay[i] * t * (t - 1) / 2;
            res = (res + s) % MOD;
            take += t;
        }
        res = (res - (take - m) % MOD * (low % MOD)) % MOD;
        res = (res + MOD) % MOD;
        return res;
    }
};