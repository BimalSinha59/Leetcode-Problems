class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            int idx;
            if (nums[i] >= 0) {
                idx = (i + nums[i]) % n;
            } else {
                idx = i + nums[i];
                idx = (idx % n + n) % n;
            }
            result[i] = nums[idx];
        }
        return result;
    }
};