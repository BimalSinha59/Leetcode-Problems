class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int ans = 0;
        int n = points.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                if (y1 >= y2) {
                    bool flg = true;
                    for (int k = i + 1; k < j && k < n; k++) {
                        int x = points[k][0], y = points[k][1];
                        if ((x1 <= x && x <= x2) && (y1 >= y && y >= y2)) {
                            flg = false;
                            break;
                        }
                    }
                    if (flg) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};