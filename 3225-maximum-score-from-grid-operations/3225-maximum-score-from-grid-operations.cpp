class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 1) {
            return 0;
        }
        vector<long long> dp_z(n + 1, 0), dp_o(n + 1, 0);
        for (int j = 1; j < n; j++) {
            vector<long long> new_dp_z(n + 1, 0), new_dp_o(n + 1, 0);
            for (int i = 0; i <= n; i++) {
                long long prev = 0;
                long long curr = 0;
                for (int x = 0; x < i; x++) {
                    curr += grid[x][j];
                }
                for (int y = 0; y <= n; y++) {
                    if (y > 0 && y <= i) {
                        curr -= grid[y - 1][j];
                    }
                    if (y > i) {
                        prev += grid[y - 1][j - 1];
                    }
                    new_dp_z[y] = max({new_dp_z[y], prev + dp_z[i], dp_o[i]});
                    new_dp_o[y] = max(
                        {new_dp_o[y], curr + dp_o[i], curr + prev + dp_z[i]});
                }
            }
            dp_z = new_dp_z;
            dp_o = new_dp_o;
        }
        return *max_element(dp_o.begin(), dp_o.end());
    }
};