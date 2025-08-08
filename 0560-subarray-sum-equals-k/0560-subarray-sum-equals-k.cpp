class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = 1;
        int psum = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            psum += nums[i];
            int diff = psum - k;
            ans += mp[diff];
            mp[psum]++;
        }
        return ans;
    }
};