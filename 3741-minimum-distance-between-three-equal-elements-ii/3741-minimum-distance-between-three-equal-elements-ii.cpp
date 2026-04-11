class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        int ans = INT_MAX;
        for (int idx = 0; idx < n; idx++) {
            mp[nums[idx]].push_back(idx);
            if (mp[nums[idx]].size() >= 3) {
                int m = mp[nums[idx]].size();
                int k = mp[nums[idx]][m - 1];
                int j = mp[nums[idx]][m - 2];
                int i = mp[nums[idx]][m - 3];
                int distance = abs(i - j) + abs(j - k) + abs(k - i);
                ans = min(ans, distance);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};