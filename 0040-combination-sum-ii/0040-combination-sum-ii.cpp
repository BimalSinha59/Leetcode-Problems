class Solution {
public:
    set<vector<int>> st;
    void f(int idx, int target, int n, vector<int>& candidates,
           vector<int>& comb, vector<vector<int>>& ans) {
            
        if (target == 0) {
            ans.push_back(comb);
            return;
        }
        for (int i = idx; i < n; i++) {
            if (i > idx && candidates[i] == candidates[i - 1]) {
                continue;
            }
            if (candidates[i] > target) {
                break;
            }
            comb.push_back(candidates[i]);
            f(i + 1, target - candidates[i], n, candidates, comb, ans);
            comb.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> comb;
        f(0, target, n, candidates, comb, ans);
        return ans;
    }
};