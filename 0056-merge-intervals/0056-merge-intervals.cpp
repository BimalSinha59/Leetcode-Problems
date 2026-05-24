class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            int prev_start = ans.back()[0];
            int prev_end = ans.back()[1];
            int curr_start = intervals[i][0];
            int curr_end = intervals[i][1];
            if (curr_start >= prev_start && curr_start <= prev_end) {
                ans.back()[1] = max(prev_end, curr_end);
            } else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};