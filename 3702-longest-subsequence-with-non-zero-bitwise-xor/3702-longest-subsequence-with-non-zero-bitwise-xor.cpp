class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        bool allz = true;
        for (auto it : nums) {
            if (it != 0) {
                allz = false;
                break;
            }
        }
        if (allz) {
            return 0;
        }
        int txor = 0;
        for (auto it : nums) {
            txor ^= it;
        }
        if (txor == 0) {
            return n - 1;
        }
        return n;
    }
};