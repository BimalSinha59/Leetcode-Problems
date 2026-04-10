class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int ans = INT_MAX;
        for (int idx = 0; idx < nums.size(); idx++) {
            mp[nums[idx]].push_back(idx);
            if (mp[nums[idx]].size() >= 3) {
                int n = mp[nums[idx]].size();
                int k = mp[nums[idx]][n - 1];
                int j = mp[nums[idx]][n - 2];
                int i = mp[nums[idx]][n - 3];
                int distance = abs(i - j) + abs(j - k) + abs(k - i);
                ans = min(ans, distance);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};