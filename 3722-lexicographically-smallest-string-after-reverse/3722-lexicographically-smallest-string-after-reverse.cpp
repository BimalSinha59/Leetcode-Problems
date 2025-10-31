class Solution {
public:
    string lexSmallest(string s) {
        int n = s.size();
        string ans = s;
        for (int i = 1; i <= n; i++) {
            string ns = s;
            reverse(ns.begin(), ns.begin() + i);
            if (ns < ans) {
                ans = ns;
            }
        }
        for (int i = n; i >= 1; i--) {
            string ns = s;
            reverse(ns.end() - i, ns.end());
            if (ns < ans) {
                ans = ns;
            }
        }
        return ans;
    }
};