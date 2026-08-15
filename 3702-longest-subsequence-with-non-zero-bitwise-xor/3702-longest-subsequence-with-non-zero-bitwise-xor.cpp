class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        bool isAllZero = true;
        int xorValue = 0;
        for (int& num : nums) {
            xorValue ^= num;
            if (num != 0) {
                isAllZero = false;
            }
        }
        if (isAllZero) {
            return 0;
        }
        if (xorValue) {
            return n;
        }
        return n - 1;
    }
};