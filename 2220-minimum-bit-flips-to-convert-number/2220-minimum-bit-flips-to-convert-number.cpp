class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorValue=(start^goal);
        int ans=__builtin_popcount(xorValue);
        return ans;
    }
};