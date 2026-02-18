class Solution {
public:
    bool hasAlternatingBits(int n) {
        int lbit = -1;
        while (n > 0) {
            int bit = n % 2;
            if (lbit != -1 && lbit == bit) {
                return false;
            }
            lbit = bit;
            n /= 2;
        }
        return true;
    }
};