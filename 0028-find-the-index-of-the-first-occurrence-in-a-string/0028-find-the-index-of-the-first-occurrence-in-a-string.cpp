class Solution {
public:
    void compute_lps(vector<int>& LPS, string& needle, int& m) {
        int len = 0;
        LPS[0] = 0;
        int i = 1;
        while (i < m) {
            if (needle[i] == needle[len]) {
                len++;
                LPS[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = LPS[len - 1];
                } else {
                    LPS[i] = 0;
                    i++;
                }
            }
        }
    }
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        vector<int> LPS(m, 0);
        compute_lps(LPS, needle, m);
        int i = 0, j = 0;
        while (i < n) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }
            if (j == m) {
                return i - m;
            } else if (haystack[i] != needle[j]) {
                if (j != 0) {
                    j = LPS[j - 1];
                } else {
                    i++;
                }
            }
        }
        return -1;
    }
};