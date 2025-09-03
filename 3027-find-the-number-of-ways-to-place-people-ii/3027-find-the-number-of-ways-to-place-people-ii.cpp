class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 1) {
            return 0;
        }

        sort(points.begin(), points.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] != b[0]) {
                     return a[0] < b[0];
                 }
                 return a[1] > b[1];
             });

        int count = 0;
        for (int i = 0; i < n; ++i) {
            int mxy = INT_MIN;
            for (int j = i + 1; j < n; ++j) {
                if (points[j][1] <= points[i][1]) {
                    if (points[j][1] > mxy) {
                        count++;
                    }
                    mxy = max(mxy, points[j][1]);
                }
            }
        }
        return count;
    }
};