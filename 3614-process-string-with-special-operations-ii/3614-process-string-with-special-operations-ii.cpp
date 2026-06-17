class Solution {
public:
    char processStr(string s, long long k) {
        long long len = 0;
        for (char& ch : s) {
            if (ch == '*') {
                if (len > 0) {
                    len--;
                }
            } else if (ch == '#') {
                len *= 2;
            } else if (ch == '%') {
                continue;
            } else {
                len++;
            }
        }
        if (k >= len) {
            return '.';
        }
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '*') {
                len++;
            } else if (s[i] == '#') {
                len /= 2;
                k = (k >= len ? k - len : k);
            } else if (s[i] == '%') {
                k = len - 1 - k;
            } else {
                len--;
            }
            if (len == k) {
                return s[i];
            }
        }
        return '.';
    }
};