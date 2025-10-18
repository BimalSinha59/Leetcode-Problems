class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int prvs = -1e9;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int curr = max(prvs + 1, nums[i] - k);
            if (curr <= nums[i] + k) {
                ans++;
                prvs = curr;
            }
        }
        return ans;
    }
};