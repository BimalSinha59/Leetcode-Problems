class Solution {
public:
    double f(double x, int n) {
        if (n % 2 == 0) {
            return f(x * x, n / 2);
        }
        if (n == 1) {
            return x;
        }
        return x * f(x, n - 1);
    }
    double myPow(double x, int n) {
        if (n < 0) {
            return 1.0 / f(x, -1LL * n);
        }
        return 1.0 * f(x, n);
    }
};