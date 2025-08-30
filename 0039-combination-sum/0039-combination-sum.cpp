class Solution {
public:
    void f(int idx, int tot, int tar, vector<int>& candidates, vector<int>& v,
           vector<vector<int>>& ans) {

        if (tot == tar) {
            ans.push_back(v);
        }
        if (tot >= tar || idx >= candidates.size()) {
            return;
        }
        v.push_back(candidates[idx]);
        f(idx, tot + candidates[idx], tar, candidates, v, ans);
        v.pop_back();
        f(idx + 1, tot, tar, candidates, v, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        f(0, 0, target, candidates, v, ans);
        return ans;
    }
};