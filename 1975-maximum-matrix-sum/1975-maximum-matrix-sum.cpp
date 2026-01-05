class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans = 0;
        int mini = 1e9;
        int ncnt = 0;
        for (auto& row : matrix) {
            for (int& cell : row) {
                ans += abs(cell);
                mini = min(mini, abs(cell));
                if (cell < 0) {
                    ncnt++;
                }
            }
        }
        if (ncnt & 1) {
            ans -= 2 * mini;
        }
        return ans;
    }
};