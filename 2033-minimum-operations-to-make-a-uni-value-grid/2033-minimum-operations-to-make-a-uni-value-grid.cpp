class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> v;
        for (auto& row : grid) {
            for (int& num : row) {
                v.push_back(num);
            }
        }
        int temp = v[0];
        for (int& num : v) {
            if (abs(num - temp) % x != 0) {
                return -1;
            }
        }
        sort(v.begin(), v.end());
        int median = v[v.size() / 2];
        int ans = 0;
        for (int num : v) {
            ans += abs(num - median) / x;
        }
        return ans;
    }
};