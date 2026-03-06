class Solution {
public:
    vector<int> makeParityAlternating(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return {0, 0};
        }
        unordered_set<int> st(nums.begin(), nums.end());
        if (st.size() == 1) {
            return {(int)n / 2, 1};
        }
        int maxi1 = INT_MIN;
        int mini1 = INT_MAX;
        int ans1 = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 != abs(nums[i]) % 2) {
                ans1++;
                maxi1 = max(maxi1, nums[i] - 1);
                mini1 = min(mini1, nums[i] + 1);
            } else {
                maxi1 = max(maxi1, nums[i]);
                mini1 = min(mini1, nums[i]);
            }
        }
        int mnValue1 = maxi1 - mini1;
        int ans2 = 0;
        int maxi2 = INT_MIN;
        int mini2 = INT_MAX;
        for (int i = 0; i < n; i++) {
            if ((i + 1) % 2 != abs(nums[i]) % 2) {
                ans2++;
                maxi2 = max(maxi2, nums[i] - 1);
                mini2 = min(mini2, nums[i] + 1);
            } else {
                maxi2 = max(maxi2, nums[i]);
                mini2 = min(mini2, nums[i]);
            }
        }
        int mnValue2 = maxi2 - mini2;
        if (ans1 == ans2) {
            if (mnValue1 <= mnValue2) {
                return {ans1, mnValue1};
            } else {
                return {ans1, mnValue2};
            }
        } else if (ans1 < ans2) {
            return {ans1, mnValue1};
        }
        return {ans2, mnValue2};
    }
};