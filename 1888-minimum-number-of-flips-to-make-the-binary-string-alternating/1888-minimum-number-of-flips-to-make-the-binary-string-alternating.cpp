class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        s = s + s;
        string s1(2 * n, '0'), s2(2 * n, '0');
        for (int i = 0; i < 2 * n; i++) {
            s1[i] = (i % 2) == 0 ? '0' : '1';
            s2[i] = (i % 2) == 0 ? '1' : '0';
        }
        int ans = 1e9;
        int ans1 = 0, ans2 = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != s1[i]) {
                ans1++;
            }
            if (s[i] != s2[i]) {
                ans2++;
            }
        }
        ans = min(ans1, ans2);
        for (int i = n; i < 2 * n; i++) {
            ans1 = ans1 - (s[i - n] == s1[i - n] ? 0 : 1) +
                   (s[i] == s1[i] ? 0 : 1);
            ans2 = ans2 - (s[i - n] == s2[i - n] ? 0 : 1) +
                   (s[i] == s2[i] ? 0 : 1);
            ans = min(ans, min(ans1, ans2));
        }
        return ans;
    }
};