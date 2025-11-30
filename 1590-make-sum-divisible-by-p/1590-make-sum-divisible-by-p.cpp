class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long sum = 0;
        for (int& it : nums) {
            sum += it;
        }
        int tgt = sum % p;
        if (tgt == 0) {
            return 0;
        }
        unordered_map<int, int> mp;
        mp[0] = -1;
        int ans = n;
        long long pfx = 0;
        for (int i = 0; i < n; i++) {
            pfx = (pfx + nums[i]) % p;
            int req = (pfx - tgt + p) % p;

            if (mp.count(req)) {
                ans = min(ans, i - mp[req]);
            }
            mp[(int)pfx] = i;
        }
        if (ans == n) {
            return -1;
        }
        return ans;
    }
};