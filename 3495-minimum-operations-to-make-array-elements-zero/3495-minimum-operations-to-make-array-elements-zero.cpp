long long expsf[18] = {0};
class Solution {
public:
    static long long expSum(unsigned x) {
        if (x == 0)
            return 0;
        int log4 = (31 - countl_zero(x)) / 2;
        int r = x - (1 << (2 * log4));
        return expsf[log4] + r * (log4 + 1LL);
    }
    static void precompute() {
        if (expsf[0] == 1)
            return;
        expsf[0] = 1;
        for (int i = 1; i < 18; i++) {
            expsf[i] = expsf[i - 1] + 3LL * i * (1LL << (2 * (i - 1))) + 1;
        }
    }
    static long long minOperations(vector<vector<int>>& queries) {
        precompute();
        long long op = 0;
        for (auto& q : queries) {
            int l = q[0] - 1, r = q[1];
            op += (expSum(r) - expSum(l) + 1) / 2;
        }
        return op;
    }
};