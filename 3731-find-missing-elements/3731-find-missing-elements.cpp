class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int lastElement = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            lastElement++;
            while (lastElement != nums[i]) {
                ans.push_back(lastElement);
                lastElement++;
            }
            lastElement = nums[i];
        }
        return ans;
    }
};