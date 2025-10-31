class Solution {
public:
    string lexSmallest(string s) {
        int n = s.size();
        string ans = s;
        for (int i = 0; i < n; i++) {
            string temp = s.substr(0, i + 1);
            reverse(temp.begin(), temp.end());
            string ns = temp + s.substr(i + 1, n - i);
            if (ns < ans) {
                ans = ns;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            string temp = s.substr(i, n - i);
            reverse(temp.begin(), temp.end());
            string ns = s.substr(0, i) + temp;
            if (ns < ans) {
                ans = ns;
            }
        }
        return ans;
    }
};