class Solution {
public:
    long long sumAndMultiply(int n) {
        int sum = 0;
        long long num = 0;
        long long mul = 1;
        while (n > 0) {
            int dig = n % 10;
            n /= 10;
            if (dig > 0) {
                sum += dig;
                num += mul * dig;
                mul *= 10;
            }
        }
        return num * sum;
    }
};