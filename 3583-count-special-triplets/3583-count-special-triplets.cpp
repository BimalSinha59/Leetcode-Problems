class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp1, mp2;
        mp1[nums[0]]++;
        for (int i = 2; i < n; i++) {
            mp2[nums[i]]++;
        }
        int ans = 0;
        int mod = 1e9 + 7;
        for (int i = 1; i < n - 1; i++) {
            ans = (ans + 1LL * mp1[2 * nums[i]] * mp2[2 * nums[i]]) % mod;
            mp1[nums[i]]++;
            mp2[nums[i + 1]]--;
        }
        return ans;
    }
};