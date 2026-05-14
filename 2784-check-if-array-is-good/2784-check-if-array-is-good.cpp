class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int& num : nums) {
            if (num >= n) {
                return false;
            }
            if (num < n - 1 && mp[num] > 0) {
                return false;
            }
            if (num == n - 1 && mp[num] > 1) {
                return false;
            }
            mp[num]++;
        }
        return true;
    }
};