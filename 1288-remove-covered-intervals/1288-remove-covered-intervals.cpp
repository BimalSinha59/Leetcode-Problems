class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) {
                 if (a[0] == b[0]) {
                     return a[1] > b[1];
                 }
                 return a[0] < b[0];
             });
        int ans = 1;
        int last_start = intervals[0][0], last_end = intervals[0][1];
        for (int i = 1; i < n; i++) {
            int curr_start = intervals[i][0];
            int curr_end = intervals[i][1];
            if (curr_start >= last_start && curr_end <= last_end) {
                continue;
            } else {
                ans++;
                last_start = curr_start;
                last_end = curr_end;
            }
        }
        return ans;
    }
};