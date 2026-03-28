class Solution {
public:
    bool solve(int idx, int& n, string& s, unordered_set<string>& st, vector<int>& dp) {
        if (idx == n) {
            return true;
        }
        if (st.find(s) != st.end()) {
            return true;
        }
        if (dp[idx] != -1) {
            return dp[idx];
        }
        for (int l = 1; l <= n; l++) {
            string str = s.substr(idx, l);
            if (st.find(str) != st.end() && solve(idx + l, n, s, st, dp)) {
                return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<int> dp(n, -1);
        return solve(0, n, s, st, dp);
    }
};