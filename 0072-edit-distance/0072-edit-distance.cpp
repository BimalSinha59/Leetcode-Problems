class Solution {
public:
    int solve(int i, int j, int& n, int& m, string& word1, string& word2, vector<vector<int>>& dp) {
        if (i == n && j == m) {
            return 0;
        }
        if (i == n) {
            return m - j;
        }
        if (j == m) {
            return n - i;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (word1[i] == word2[j]) {
            return dp[i][j] = solve(i + 1, j + 1, n, m, word1, word2, dp);
        }
        int insert_op = 1 + solve(i, j + 1, n, m, word1, word2, dp);
        int delete_op = 1 + solve(i + 1, j, n, m, word1, word2, dp);
        int replace_op = 1 + solve(i + 1, j + 1, n, m, word1, word2, dp);
        return dp[i][j] = min({insert_op, delete_op, replace_op});
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(0, 0, n, m, word1, word2, dp);
    }
};