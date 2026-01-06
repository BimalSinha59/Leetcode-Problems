class Solution {
public:
    void computeLPS(string& str, vector<int>& LPS) {
        int m = str.size();
        int len = 0;
        LPS[0] = 0;
        int i = 1;
        while (i < m) {
            if (str[i] == str[len]) {
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
    string shortestPalindrome(string s) {
        int n = s.size();
        string rs = s;
        reverse(rs.begin(), rs.end());
        string ns = s + "#" + rs;
        vector<int> LPS(ns.size(), 0);
        computeLPS(ns, LPS);
        int len = LPS[ns.size() - 1];
        string culprit = rs.substr(0, n - len);
        return culprit + s;
    }
};