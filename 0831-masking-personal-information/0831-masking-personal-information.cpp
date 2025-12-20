class Solution {
public:
    string maskPII(string s) {
        int n = s.size();
        string ans;
        if ((s[0] >= 'a' && s[0] <= 'z') || (s[0] >= 'A' && s[0] <= 'Z')) {
            ans.push_back(tolower(s[0]));
            ans += "*****";
            int idx;
            for (int i = 0; i < n; i++) {
                if (s[i] == '@') {
                    idx = i;
                }
            }
            ans.push_back(tolower(s[idx - 1]));
            ans.push_back('@');
            for (int i = idx + 1; i < n; i++) {
                if (s[i] != '.') {
                    s[i] = tolower(s[i]);
                }
                ans.push_back(s[i]);
            }
        } else {
            int ds = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] >= '0' && s[i] <= '9') {
                    ds++;
                }
            }
            for (int i = n - 1;; i--) {
                if (s[i] >= '0' && s[i] <= '9') {
                    ans.push_back(s[i]);
                    if (ans.size() == 4) {
                        break;
                    }
                }
            }
            ans.push_back('-');
            ans += "***-***";
            int rem = ds - 10;
            if (rem == 1) {
                ans += "-*+";
            } else if (rem == 2) {
                ans += "-**+";
            } else if (rem == 3) {
                ans += "-***+";
            }
            reverse(ans.begin(), ans.end());
        }
        return ans;
    }
};