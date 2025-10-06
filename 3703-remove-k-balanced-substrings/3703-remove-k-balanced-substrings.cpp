class Solution {
public:
    string removeSubstring(string s, int k) {
        string ans;
        int n = s.size();
        int i = 0;
        while (i < n) {
            if (s[i] == '(') {
                ans.push_back(s[i]);
                i++;
            } else {
                int cnt1 = 0;
                int j = ans.size() - 1;
                while (j >= 0 && ans[j] == ')') {
                    cnt1++;
                    j--;
                }
                int cnt2 = cnt1;
                while (i < n && s[i] == ')') {
                    cnt2++;
                    i++;
                    if (cnt2 == k) {
                        break;
                    }
                }
                int cnt3 = 0;
                while (j >= 0 && ans[j] == '(') {
                    cnt3++;
                    if (cnt3 == k) {
                        break;
                    }
                    j--;
                }
                if (cnt3 == k && cnt2 == k) {
                    int x = k + cnt1;
                    while (x--) {
                        ans.pop_back();
                    }
                } else {
                    int x = cnt2 - cnt1;
                    while (x--) {
                        ans.push_back(')');
                    }
                }
            }
        }
        return ans;
    }
};