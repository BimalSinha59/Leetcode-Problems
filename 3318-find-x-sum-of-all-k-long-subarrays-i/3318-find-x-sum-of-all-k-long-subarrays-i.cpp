class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i <= n - k; i++) {
            unordered_map<int, int> mp;
            for (int j = i; j < i + k; j++) {
                mp[nums[j]]++;
            }
            vector<pair<int, int>> v;
            for (auto& it : mp) {
                v.push_back({it.second, it.first});
            }
            sort(v.rbegin(), v.rend());
            int m = v.size();
            int sum = 0;
            for (int j = 0; j < x && j < m; j++) {
                sum += (v[j].first * v[j].second);
            }
            ans.push_back(sum);
        }
        return ans;
    }
};