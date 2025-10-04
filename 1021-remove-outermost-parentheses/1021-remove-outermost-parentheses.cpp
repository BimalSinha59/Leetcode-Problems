class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        string ans;
        int i = 0, j = 0;
        int cnt = 0;
        while (j < n) {
            if (s[j] == '(') {
                cnt++;
                j++;
            } 
            else {
                cnt--;
                j++;
            }
            if (cnt == 0) {
                ans += s.substr(i + 1, j - i - 2);
                i = j;
            }
        }
        return ans;
    }
};