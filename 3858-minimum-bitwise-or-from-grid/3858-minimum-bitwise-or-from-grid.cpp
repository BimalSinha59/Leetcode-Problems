class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 20; i >= 0; i--) {
            int b = 1 << i;
            int mask = ans | (b - 1);
            for (auto& r : grid) {
                bool flg = true;
                for (int a : r) {
                    if ((a & mask) == a) {
                        flg = false;
                        break;
                    }
                }
                if (flg) {
                    ans |= b;
                    break;
                }
            }
        }
        return ans;
    }
};