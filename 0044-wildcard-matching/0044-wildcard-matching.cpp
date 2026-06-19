class Solution {
public:
    bool allStar(int j, string& p, int& m) {
        for (int i = j; i < m; i++) {
            if (p[i] != '*') {
                return false;
            }
        }
        return true;
    }
    bool solve(int i, int j, int& n, int& m, string& s, string& p,
               vector<vector<int>>& dp) {
        if (i == n && j == m) {
            return true;
        }
        if (j == m && i < n) {
            return false;
        }
        if (i == n && j < m) {
            return allStar(j, p, m);
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = solve(i + 1, j + 1, n, m, s, p, dp);
        }
        if (p[j] == '*') {
            return dp[i][j] = solve(i, j + 1, n, m, s, p, dp) |
                              solve(i + 1, j, n, m, s, p, dp);
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(0, 0, n, m, s, p, dp);
    }
};