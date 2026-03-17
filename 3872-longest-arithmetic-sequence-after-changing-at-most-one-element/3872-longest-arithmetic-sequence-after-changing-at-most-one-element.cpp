class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int n = nums.size();
        int ans = 2;
        vector<int> lpa(n, 2);
        vector<int> lsa(n, 2);
        for (int i = 2; i < n; i++) {
            if (nums[i - 1] - nums[i - 2] == nums[i] - nums[i - 1]) {
                lpa[i] = lpa[i - 1] + 1;
            }
        }
        for (int i = n - 3; i >= 0; i--) {
            if (nums[i + 2] - nums[i + 1] == nums[i + 1] - nums[i]) {
                lsa[i] = lsa[i + 1] + 1;
            }
        }
        for (int i = 0; i < n; i++) {
            ans = max(ans, max(lpa[i], lsa[i]));
            if (i == 0) {
                ans = max(ans, 1 + lsa[i + 1]);
            } else if (i == n - 1) {
                ans = max(ans, 1 + lpa[i - 1]);
            } else {
                ans = max(ans, 1 + lpa[i - 1]);
                ans = max(ans, 1 + lsa[i + 1]);
                if (((nums[i + 1] - nums[i - 1]) % 2) == 0) {
                    int need = (nums[i + 1] - nums[i - 1]) / 2;
                    int lLen = 1, rLen = 1;
                    if (i >= 2 && (nums[i - 1] - nums[i - 2] == need)) {
                        lLen = lpa[i - 1];
                    }
                    if (i + 2 < n && (nums[i + 2] - nums[i + 1] == need)) {
                        rLen = lsa[i + 1];
                    }
                    ans = max(ans, 1 + lLen + rLen);
                }
            }
        }
        return ans;
    }
};