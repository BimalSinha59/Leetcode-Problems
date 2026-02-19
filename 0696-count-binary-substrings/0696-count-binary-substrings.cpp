class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int ans = 0;
        int lcnt = 0;
        int ccnt = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                ccnt++;
            } else {
                if (lcnt != 0) {
                    ans += min(lcnt, ccnt);
                }
                lcnt = ccnt;
                ccnt = 1;
            }
        }
        ans += min(lcnt, ccnt);
        return ans;
    }
};