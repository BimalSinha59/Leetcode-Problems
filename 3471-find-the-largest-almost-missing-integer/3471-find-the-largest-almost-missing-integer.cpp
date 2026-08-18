class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        map<int, int> freq;
        for (int& num : nums) {
            freq[num]++;
        }
        if (k == nums.size()) {
            return freq.rbegin()->first;
        }
        for (auto it = freq.rbegin(); it != freq.rend(); it++) {
            if (it->second == 1 && k == 1) {
                return it->first;
            }
            if (it->second == 1 &&
                (it->first == nums[0] || it->first == nums[nums.size() - 1])) {
                return it->first;
            }
        }
        return -1;
    }
};