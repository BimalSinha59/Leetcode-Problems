class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int idx1 = n, idx2 = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'b') {
                idx1 = i;
                break;
            }
        }
        int cnt1 = 0;
        for (int i = idx1 + 1; i < n; i++) {
            if (s[i] == 'a') {
                cnt1++;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == 'a') {
                idx2 = i;
                break;
            }
        }
        int cnt2 = 0;
        for (int i = idx2 - 1; i >= 0; i--) {
            if (s[i] == 'b') {
                cnt2++;
            }
        }
        int ans = 1e9;
        int c1 = 0;
        for (int i = idx1; i < n; i++) {
            ans = min(ans, c1 + cnt1);
            if (s[i] == 'a') {
                cnt1--;
            } else {
                c1++;
            }
        }
        ans = min(ans, c1);
        int c2 = 0;
        for (int i = idx2; i >= 0; i--) {
            ans = min(ans, c2 + cnt2);
            if (s[i] == 'b') {
                cnt2--;
            } else {
                c2++;
            }
        }
        ans = min(ans, c2);
        return ans;
    }
};