class Solution {
public:
    long long total;
    bool checkHorCuts(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        unordered_set<long long> st;
        long long top = 0;

        for (int i = 0; i <= m - 2; i++) {

            for (int j = 0; j < n; j++) {
                st.insert(grid[i][j]);
                top += grid[i][j];
            }

            long long bottom = (total - top);
            long long diff = top - bottom;

            if (diff == 0)
                return true;

            if (diff == (long long)grid[0][0])
                return true;
            if (diff == (long long)grid[0][n - 1])
                return true;
            if (diff == (long long)grid[i][0])
                return true;

            if (i > 0 && n > 1 && st.count(diff)) {
                return true;
            }
        }

        return false;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                total += grid[i][j];
            }
        }

        if (checkHorCuts(grid)) {
            return true;
        }

        reverse(begin(grid), end(grid));

        if (checkHorCuts(grid)) {
            return true;
        }

        reverse(begin(grid), end(grid));
        vector<vector<int>> transposeGrid(n, vector<int>(m));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                transposeGrid[j][i] = grid[i][j];
            }
        }

        if (checkHorCuts(transposeGrid)) {
            return true;
        }

        reverse(begin(transposeGrid), end(transposeGrid));

        if (checkHorCuts(transposeGrid)) {
            return true;
        }
        return false;
    }
};