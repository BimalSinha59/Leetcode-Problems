class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 1) {
            return dividend;
        }
        if (divisor == -1) {
            return dividend == INT_MIN ? INT_MAX : -dividend;
        }
        bool isPositive = (dividend > 0) == (divisor > 0);
        int a = dividend > 0 ? -dividend : dividend;
        int b = divisor > 0 ? -divisor : divisor;
        int ans = 0;
        while (a <= b) {
            int temp = b, mul = 1;
            while (temp >= (INT_MIN >> 1) && a <= (temp << 1)) {
                temp <<= 1;
                mul <<= 1;
            }
            a -= temp;
            ans += mul;
        }
        return isPositive ? ans : -ans;
    }
};