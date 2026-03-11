class Solution {
public:
    int bitwiseComplement(int n) {
        unsigned int num = n;
        if (n == 0) {
            return 1;
        }
        int mask = (1 << bit_width(num)) - 1;
        return (~n & mask);
    }
};