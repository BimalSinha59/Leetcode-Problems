class Solution {
public:
    int y_lim(vector<int>& left, vector<int>& right) {
        int x1 = left[0], y1 = left[1];
        int x2 = right[0], y2 = right[1];
        return min(y2, y1 + abs(x2 - x1));
    }
    int y_peak(vector<int>& left, vector<int>& right) {
        int x1 = left[0], y1 = left[1];
        int x2 = right[0], y2 = right[1];
        return (y1 + y2 + x2 - x1) / 2;
    }
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        restrictions.push_back({n, n - 1});
        int m = restrictions.size();
        sort(restrictions.begin(), restrictions.end());
        for (int i = 1; i < m; i++) {
            restrictions[i][1] = y_lim(restrictions[i - 1], restrictions[i]);
        }
        for (int i = m - 2; i >= 0; i--) {
            restrictions[i][1] = y_lim(restrictions[i + 1], restrictions[i]);
        }
        int maxHeight = 0;
        for (int i = 1; i < m; i++) {
            int height = y_peak(restrictions[i - 1], restrictions[i]);
            maxHeight = max(maxHeight, height);
        }
        return maxHeight;
    }
};