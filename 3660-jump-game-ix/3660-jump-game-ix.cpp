class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> p_max(n), s_min(n), ans(n);
        p_max[0] = nums[0];
        for (int i = 1; i < n; i++) {
            p_max[i] = max(p_max[i - 1], nums[i]);
        }
        s_min[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            s_min[i] = min(s_min[i + 1], nums[i]);
        }
        ans[n - 1] = p_max[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (p_max[i] > s_min[i + 1]) {
                ans[i] = ans[i + 1];
            } else {
                ans[i] = p_max[i];
            }
        }
        return ans;
    }
};