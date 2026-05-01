class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> s_min(n);
        s_min[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            s_min[i] = min(nums[i], s_min[i + 1]);
        }
        int maxi = 0;
        int ans = -1;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            if (maxi - s_min[i] <= k) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};