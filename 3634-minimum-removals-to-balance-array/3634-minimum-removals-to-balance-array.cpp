class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        if (n <= 1)
            return 0;
        sort(nums.begin(), nums.end());
        int maxi = 1;
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (j < i) {
                j = i;
            }
            while (j + 1 < n && nums[j + 1] <= k * 1LL * nums[i]) {
                j++;
            }
            if (nums[j] <= k * 1LL * nums[i]) {
                maxi = max(maxi, j - i + 1);
            }
        }
        return n - maxi;
    }
};