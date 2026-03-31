class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        long long xorr = 0;
        for (int i = 0; i < n; i++) {
            xorr ^= nums[i];
        }
        long long rightMost = (xorr & (xorr - 1)) ^ xorr;
        long long num1 = 0, num2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] & rightMost) {
                num1 ^= nums[i];
            } else {
                num2 ^= nums[i];
            }
        }
        return {(int)num1, (int)num2};
    }
};