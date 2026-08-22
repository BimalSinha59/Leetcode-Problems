class Solution {
public:
    bool checkDivisibility(int n) {
        int digSum = 0;
        int digMul = 1;
        int num = n;
        while (n > 0) {
            int dig = n % 10;
            digSum += dig;
            digMul *= dig;
            n /= 10;
        }
        int sum = digSum + digMul;
        return num % sum == 0;
    }
};