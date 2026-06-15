class Solution {
public:
    int maxCherry(int r1, int c1, int r2, vector<vector<int>>& grid, int n, vector<vector<vector<int>>>& dp) {
        int c2 = r1 + c1 - r2;

        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n || grid[r1][c1] == -1 ||
            grid[r2][c2] == -1) {
            return -1e9;
        }

        if (r1 == n - 1 && c1 == n - 1) {
            return grid[r1][c1];
        }

        if (dp[r1][c1][r2] != -1) {
            return dp[r1][c1][r2];
        }

        int cherries = 0;
        if (r1 == r2 && c1 == c2) {
            cherries = grid[r1][c1];
        } else {
            cherries = grid[r1][c1] + grid[r2][c2];
        }

        int f1 = maxCherry(r1, c1 + 1, r2, grid, n, dp);
        int f2 = maxCherry(r1 + 1, c1, r2 + 1, grid, n, dp);
        int f3 = maxCherry(r1, c1 + 1, r2 + 1, grid, n, dp);
        int f4 = maxCherry(r1 + 1, c1, r2, grid, n, dp);
        cherries += max({f1, f2, f3, f4});
        return dp[r1][c1][r2] = cherries;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
        int ans = maxCherry(0, 0, 0, grid, n, dp);
        return max(0, ans);
    }
};