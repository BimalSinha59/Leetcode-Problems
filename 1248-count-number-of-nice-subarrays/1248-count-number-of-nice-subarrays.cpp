class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int ans = 0;
        int psum = 0;
        mp[0] = 1;
        for (int i = 0; i < n; i++) {
            psum += nums[i] % 2;
            int diff = psum - k;
            ans += mp[diff];
            mp[psum]++;
        }
        return ans;
    }
};