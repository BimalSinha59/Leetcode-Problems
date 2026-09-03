class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini = INT_MAX;
        int odd_counts = 0;
        for (int& num : nums1) {
            mini = min(mini, num);
            if (num & 1) {
                odd_counts++;
            }
        }
        if (odd_counts == 0 || (mini & 1)) {
            return true;
        }
        return false;
    }
};