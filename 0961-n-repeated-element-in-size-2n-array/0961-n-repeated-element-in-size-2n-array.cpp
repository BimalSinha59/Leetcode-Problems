class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int& it : nums) {
            if (mp[it]) {
                return it;
            }
            mp[it]++;
        }
        return 0;
    }
};