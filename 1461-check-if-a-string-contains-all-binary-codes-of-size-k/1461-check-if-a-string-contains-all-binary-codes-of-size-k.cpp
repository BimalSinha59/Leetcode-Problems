class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int req = 1 << k;
        bitset<1048576> seen;
        int msk = req - 1;
        int hash = 0;

        for (int i = 0; i < s.size(); ++i) {
            hash = ((hash << 1) & msk) | (s[i] & 1);
            if (i >= k - 1 && !seen[hash]) {
                seen[hash] = 1;
                req--;
                if (req == 0) {
                    return true;
                }
            }
        }
        return false;
    }
};