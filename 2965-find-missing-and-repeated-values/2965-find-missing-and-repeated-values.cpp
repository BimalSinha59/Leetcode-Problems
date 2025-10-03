class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        long long s1 = 0;
        long long ss1 = 0;
        for (auto it : grid) {
            for (auto i : it) {
                s1 += i;
                ss1 += i * i;
            }
        }
        long long m = n * n;
        long long s2 = (m * (m + 1)) / 2;
        long long ss2 = (m * (m + 1) * (2 * m + 1)) / 6;
        long long d = s1 - s2;
        long long sd = ss1 - ss2;
        int rvalue = (sd + d * d) / (2 * d);
        int mvalue = (sd - d * d) / (2 * d);
        return {rvalue, mvalue};
    }
};