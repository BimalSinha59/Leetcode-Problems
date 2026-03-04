class Solution {
public:
    string maximumXor(string s, string t) {
        int os = 0, zs = 0;
        for (char c : t) {
            if (c == '1') {
                os++;
            }
            else{
                 zs++;
            }
        }
        string ans = "";
        for (char c : s) {
            if (c == '1') {
                if (zs > 0) {
                    ans += '1';
                    zs--;
                } else {
                    ans += '0';
                    os--;
                }
            } else {
                if (os > 0) {
                    ans += '1';
                    os--;
                } else {
                    ans += '0';
                    zs--;
                }
            }
        }
        return ans;
    }
};