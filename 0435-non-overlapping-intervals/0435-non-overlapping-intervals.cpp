class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(),[](vector<int>& a, vector<int>& b) { 
            return a[1] < b[1]; 
        });
        int cnt = 1;
        int last_end = intervals[0][1];
        for (int i = 1; i < n; i++) {
            int curr_start = intervals[i][0];
            int curr_end = intervals[i][1];
            if (curr_start >= last_end) {
                cnt++;
                last_end = curr_end;
            }
        }
        return n - cnt;
    }
};