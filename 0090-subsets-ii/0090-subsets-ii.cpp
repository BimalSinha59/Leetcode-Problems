class Solution {
public:
    void solve(int idx, int& n, vector<int>& curr, vector<int>& nums, vector<vector<int>>& ans) {
        ans.push_back(curr);
        for (int i = idx; i < n; i++) {
            if (i > idx && nums[i] == nums[i - 1]) {
                continue;
            }
            curr.push_back(nums[i]);
            solve(i + 1, n, curr, nums, ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        solve(0, n, curr, nums, ans);
        return ans;
    }
};