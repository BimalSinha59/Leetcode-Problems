class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries,
                                     int x) {
        int n = nums.size();
        vector<int> idxs;
        for (int i = 0; i < n; i++) {
            if (nums[i] == x) {
                idxs.push_back(i);
            }
        }
        vector<int> ans;
        for (int& occ : queries) {
            occ--;
            if (occ >= idxs.size()) {
                ans.push_back(-1);
            } else {
                ans.push_back(idxs[occ]);
            }
        }
        return ans;
    }
};