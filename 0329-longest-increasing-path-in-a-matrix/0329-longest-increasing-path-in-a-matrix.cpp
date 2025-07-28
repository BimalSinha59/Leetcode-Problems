class Solution {
public:
    int dfs(int r, int c, vector<vector<int>>& matrix, vector<vector<int>>& dp, int dr[], int dc[], int n, int m) {
        if(dp[r][c] != -1) return dp[r][c];
        int maxLen = 1;
        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && matrix[nr][nc] > matrix[r][c]) {
                maxLen = max(maxLen, 1 + dfs(nr, nc, matrix, dp, dr, dc, n, m));
            }
        }
        return dp[r][c] = maxLen;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int lip = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                lip = max(lip, dfs(i, j, matrix, dp, dr, dc, n, m));
            }
        }
        return lip;
    }
};
