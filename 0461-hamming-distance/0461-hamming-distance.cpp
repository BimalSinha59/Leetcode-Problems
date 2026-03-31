class Solution {
public:
    int hammingDistance(int x, int y) {
        int xorValue = (x^y);
        int ans = __builtin_popcount(xorValue);
        return ans;
    }
};