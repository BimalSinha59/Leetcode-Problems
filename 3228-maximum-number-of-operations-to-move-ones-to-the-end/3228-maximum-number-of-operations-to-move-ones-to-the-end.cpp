class Solution {
public:
    int maxOperations(string s) {
        int n=s.size();
        int os = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                while ((i + 1) < n && s[i + 1] == '0') {
                    i++;
                }
                ans += os;
            } else {
                os++;
            }
        }
        return ans;
    }
};