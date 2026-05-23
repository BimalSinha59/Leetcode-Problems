class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty()) {
            return {newInterval};
        }
        int n = intervals.size();
        int idx = -1;
        int low = 0, high = n - 1;
        int target = newInterval[0];
        while (low <= high) {
            int mid = (low + high) / 2;
            if (intervals[mid][0] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        intervals.insert(intervals.begin() + low, newInterval);
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for (int i = 1; i <= n; i++) {
            int c_start = intervals[i][0];
            int c_end = intervals[i][1];
            int p_start = ans.back()[0];
            int p_end = ans.back()[1];
            if (c_start >= p_start && c_start <= p_end) {
                ans.back()[1] = max(p_end, c_end);
            } else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};