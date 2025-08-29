class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) { 
        return a[1]<b[1];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), cmp);
        ans.push_back({intervals[0][0], intervals[0][1]});
        for (int i = 1; i < intervals.size(); i++) {
            int ps = ans.back()[0];
            int pe = ans.back()[1];
            int cs = intervals[i][0];
            int ce = intervals[i][1];
            if ((cs >= ps && cs <= pe)) {
                ans.back()[1] = ce;
            } 
            else if(pe>=cs && pe<=ce){
                ans.pop_back();
                ans.push_back({cs, ce});
            }
            else {
                ans.push_back({cs, ce});
            }
        }
        return ans;
    }
};