class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        vector<long long> ans(n);
        for (const auto& p : mp) {
            const auto& v = p.second;
            long long total = accumulate(v.begin(), v.end(), 0LL);
            long long pTotal = 0;
            for (int i = 0; i < v.size(); i++) {
                ans[v[i]] = total - pTotal * 2 + v[i] * (2 * i - v.size());
                pTotal += v[i];
            }
        }
        return ans;
    }
};