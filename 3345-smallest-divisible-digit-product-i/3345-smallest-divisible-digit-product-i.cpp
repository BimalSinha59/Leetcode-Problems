class Solution {
public:
    int smallestNumber(int n, int t) {
        for (int i = n;; i++) {
            int product = 1;
            int num = i;
            while (num > 0) {
                int dig = num % 10;
                product *= dig;
                if (product == 0) {
                    return i;
                }
                num /= 10;
            }
            if (product % t == 0) {
                return i;
            }
        }
        return 0;
    }
};