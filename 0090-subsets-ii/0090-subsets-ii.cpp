class Solution {
public:
    void f(int ind, int n, vector<int>& nums, vector<int> v,
           vector<vector<int>>& ans, set<vector<int>>& st) {

        if (ind == n) {
            sort(v.begin(),v.end());
            if (st.find(v) == st.end()) {
                ans.push_back(v);
                st.insert(v);
            }
            return;
        }
        v.push_back(nums[ind]);
        f(ind + 1, n, nums, v, ans, st);
        v.pop_back();
        f(ind + 1, n, nums, v, ans, st);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        set<vector<int>> st;
        f(0, nums.size(), nums, v, ans, st);
        return ans;
    }
};