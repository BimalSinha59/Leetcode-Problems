class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        int hash[256] = {0};
        for (int i = 0; i < m; i++) {
            hash[t[i]]++;
        }
        int l = 0, sIdx = -1, mnLen = 1e9, cnt = 0;
        for (int r = 0; r < n; r++) {
            if (hash[s[r]] > 0) {
                cnt++;
            }
            hash[s[r]]--;
            while (cnt == m) {
                int len = r - l + 1;
                if (len < mnLen) {
                    sIdx = l;
                    mnLen = len;
                }
                hash[s[l]]++;
                if (hash[s[l]] > 0) {
                    cnt--;
                }
                l++;
            }
        }
        if (sIdx == -1) {
            return "";
        }
        return s.substr(sIdx, mnLen);
    }
};