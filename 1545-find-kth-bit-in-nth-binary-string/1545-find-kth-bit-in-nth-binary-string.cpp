class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        for (int i = 1; i < n; i++) {
            string str = s;
            for (int j = 0; j < str.size(); j++) {
                if (str[j] == '1') {
                    str[j] = '0';
                } else {
                    str[j] = '1';
                }
            }
            reverse(str.begin(), str.end());
            s = s + "1" + str;
        }
        return s[k - 1];
    }
};