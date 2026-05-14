class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int& num : nums) {
            mp[num]++;
        }
        for (int i = 1; i < n - 1; i++) {
            if (mp[i] != 1) {
                cout << i;
                return false;
            }
        }
        if (mp[n - 1] != 2) {
            return false;
        }
        return true;
    }
};