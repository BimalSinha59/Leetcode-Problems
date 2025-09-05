class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (int k = 1; k <= 60; k++) {
            long long diff = (long long)num1 - (long long)num2 * k;
            if (diff < 0) continue;
            int sbits = __builtin_popcountll(diff);
            if (sbits <= k && k <= diff) {
                return k;
            }
        }
        return -1;
    }
};
