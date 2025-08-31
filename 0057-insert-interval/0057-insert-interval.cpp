class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
                                
        vector<vector<int>> temp;
        int i;
        for (i = 0; i < intervals.size(); i++) {
            if (intervals[i][0] < newInterval[0] &&
                intervals[i][1] <= newInterval[1]) {
                temp.push_back({intervals[i][0], intervals[i][1]});
            } 
            else {
                break;
            }
        }
        temp.push_back({newInterval[0], newInterval[1]});
        for (i = i; i < intervals.size(); i++) {
            temp.push_back({intervals[i][0], intervals[i][1]});
        }
        vector<vector<int>> ans;
        ans.push_back({temp[0][0], temp[0][1]});
        for (int i = 1; i < temp.size(); i++) {
            int ps = ans.back()[0];
            int pe = ans.back()[1];
            int cs = temp[i][0];
            int ce = temp[i][1];
            if (pe < cs) {
                ans.push_back({cs, ce});
            } 
            else {
                pe = max(pe, ce);
                ans.back()[1] = pe;
            }
        }
        return ans;
    }
};