class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        if (n % k != 0) {
            return false;
        }
        unordered_map<int, int> mp;
        for (auto it : nums) {
            mp[it]++;
        }
        int m = n / k;
        for (auto it : mp) {
            if (it.second > m) {
                return false;
            }
        }
        return true;
    }
};