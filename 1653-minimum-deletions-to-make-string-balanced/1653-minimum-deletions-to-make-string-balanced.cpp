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
        int ans1 = 0;
        for (int i = idx1 + 1; i < n; i++) {
            if (s[i] == 'a') {
                ans1++;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == 'a') {
                idx2 = i;
                break;
            }
        }
        int ans2 = 0;
        for (int i = idx2 - 1; i >= 0; i--) {
            if (s[i] == 'b') {
                ans2++;
            }
        }
        return min(ans1, ans2);
    }
};