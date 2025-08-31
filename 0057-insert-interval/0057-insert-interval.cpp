class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        ans.push_back({intervals[0][0], intervals[0][1]});
        for (int i = 1; i < intervals.size(); i++) {
            int ps = ans.back()[0];
            int pe = ans.back()[1];
            int cs = intervals[i][0];
            int ce = intervals[i][1];
            if (pe < cs) {
                ans.push_back({cs, ce});
            } else {
                pe = max(pe, ce);
                ans.back()[1] = pe;
            }
        }
        return ans;
    }
};