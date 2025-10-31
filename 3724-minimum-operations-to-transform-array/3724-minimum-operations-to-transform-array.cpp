class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        long long ans = 0;
        int mini = 1e9;
        for (int i = 0; i < n; i++) {
            int diff = abs(nums1[i] - nums2[i]);
            ans += diff;
            if (min(nums1[i], nums2[i]) <= nums2[n] &&
                nums2[n] <= max(nums1[i], nums2[i])) {
                mini = 0;
            } else {
                int temp =
                    min(abs(nums2[n] - nums1[i]), abs(nums2[n] - nums2[i]));
                mini = min(mini, temp);
            }
        }
        return ans + mini + 1;
    }
};