class Solution {
public:
    int pfunc(vector<int>& nums, int n, int cap) {
        int sum = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (sum > cap) {
                sum = nums[i];
                ans++;
            }
        }
        ans++;
        return ans;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int s = *max_element(nums.begin(), nums.end());
        int e = accumulate(nums.begin(), nums.end(), 0);
        int ans;
        while (s <= e) {
            int mid = (s + e) / 2;
            if (pfunc(nums, n, mid) <= k) {
                ans = mid;
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
        }
        return ans;
    }
};