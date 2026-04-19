class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int i = 0, j = m - 1;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int s = i, e = m - 1;
            while (s <= e) {
                int mid = (s + e) / 2;
                if (nums2[mid] >= nums1[i]) {
                    ans = max(ans, mid - i);
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }
        }
        return ans;
    }
};