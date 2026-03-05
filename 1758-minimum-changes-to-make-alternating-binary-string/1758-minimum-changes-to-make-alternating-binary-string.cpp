class Solution {
public:
    int solve(string& s, int n, int lchar) {
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] == lchar) {
                ans++;
                lchar = (lchar == '0' ? '1' : '0');
            } else {
                lchar = s[i];
            }
        }
        return ans;
    }
    int minOperations(string s) {
        int n = s.size();
        int ans1 = solve(s, n, '0');
        int ans2 = solve(s, n, '1');
        if (s[0] == '0') {
            ans2++;
        } else {
            ans1++;
        }
        return min(ans1, ans2);
    }
};