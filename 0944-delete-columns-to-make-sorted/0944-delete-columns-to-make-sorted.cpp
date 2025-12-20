class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            char lch;
            for (int j = 0; j < n; j++) {
                if (j != 0) {
                    if (strs[j][i] < lch) {
                        ans++;
                        break;
                    }
                }
                lch = strs[j][i];
            }
        }
        return ans;
    }
};