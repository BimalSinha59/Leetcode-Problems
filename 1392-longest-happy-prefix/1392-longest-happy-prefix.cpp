class Solution {
public:
    void computeLPS(string& s, vector<int>& LPS, int n) {
        LPS[0] = 0;
        int len = 0;
        int i = 1;
        while (i < n) {
            if (s[i] == s[len]) {
                len++;
                LPS[i] = len;
                i++;
            } else {
                if (len - 1 >= 0) {
                    len = LPS[len - 1];
                } else {
                    LPS[i] = 0;
                    i++;
                }
            }
        }
    }
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> LPS(n, 0);
        computeLPS(s, LPS, n);
        int lhpLen = LPS[n - 1];
        return s.substr(0, lhpLen);
    }
};