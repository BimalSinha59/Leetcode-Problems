class Solution {
public:
    int magicalString(int n) {
        string s = "12";
        for (int i = 1;; i++) {
            if (s[i] == '2') {
                if (i == 1) {
                    s.push_back('2');
                } else {
                    if (s.back() == '1') {
                        s += "22";
                    } else {
                        s += "11";
                    }
                }
            } else {
                if (s.back() == '1') {
                    s.push_back('2');
                } else {
                    s.push_back('1');
                }
            }
            if (s.size() >= n) {
                break;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                ans++;
            }
        }
        return ans;
    }
};