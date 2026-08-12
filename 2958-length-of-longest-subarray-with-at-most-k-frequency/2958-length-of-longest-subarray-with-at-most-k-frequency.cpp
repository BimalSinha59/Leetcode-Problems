class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int lgs = 0;
        int left = 0, max_freq = 0;
        unordered_map<int, int> mp;
        int ele = -1;
        for (int right = 0; right < n; right++) {
            mp[nums[right]]++;
            if (mp[nums[right]] > max_freq) {
                ele = nums[right];
                max_freq = mp[nums[right]];
            }
            while (max_freq > k) {
                mp[nums[left]]--;
                if (nums[left] == ele) {
                    max_freq--;
                }
                left++;
            }
            int len = right - left + 1;
            lgs = max(lgs, len);
        }
        return lgs;
    }
};