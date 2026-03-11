class Solution {
public:
    int findComplement(int num) {
        unsigned int n = num;
        int mask = (1 << bit_width(n));
        if (mask == INT_MIN) {
            mask = INT_MAX;
        } else {
            mask--;
        }
        int ans = (~num & mask);
        return ans;
    }
};