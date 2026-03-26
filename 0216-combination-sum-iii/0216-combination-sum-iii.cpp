class Solution {
public:
    void solve(int idx, int& k, int tgt, int& sz, vector<int>& nums,
               vector<int>& curr, vector<vector<int>>& ans) {
                
        if (tgt == 0) {
            if (curr.size() == k) {
                ans.push_back(curr);
            }
            return;
        }
        if (tgt < 0 || idx >= sz || curr.size() > k) {
            return;
        }
        curr.push_back(nums[idx]);
        solve(idx + 1, k, tgt - nums[idx], sz, nums, curr, ans);
        curr.pop_back();
        solve(idx + 1, k, tgt, sz, nums, curr, ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> curr;
        vector<vector<int>> ans;
        int sz = 9;
        solve(0, k, n, sz, nums, curr, ans);
        return ans;
    }
};