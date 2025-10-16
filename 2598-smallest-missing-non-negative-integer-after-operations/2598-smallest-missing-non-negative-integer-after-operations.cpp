class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
        vector<int> mp(value, 0);
        for (int i = 0; i < n; i++) {
            int x = (nums[i] % value + value) % value;
            mp[x]++;
        }
        int ans = 0;
        while (mp[ans % value] > 0) {
            mp[ans % value]--;
            ans++;
        }
        return ans;
    }
};