class Solution {
public:
    bool isPalindrome(int l, int r, string& s) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    void solve(int i, int& n, string& s, vector<string>& ans, vector<vector<string>>& res) {
        if (i == n) {
            res.push_back(ans);
            return;
        }
        for (int j = i; j < n; j++) {
            if (isPalindrome(i, j, s)) {
                ans.push_back(s.substr(i, j - i + 1));
                solve(j + 1, n, s, ans, res);
                ans.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<string> ans;
        vector<vector<string>> res;
        solve(0, n, s, ans, res);
        return res;
    }
};