class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        int n = capacity.size();
        unordered_map<long long, unordered_map<long long, long long>> mp;
        long long ans = 0, prs = 0;
        for (int i = 0; i < n; i++) {
            if (mp.count(capacity[i]) &&
                mp[capacity[i]].count(prs - capacity[i])) {
                ans += mp[capacity[i]][prs - capacity[i]];
            }
            prs += capacity[i];
            mp[capacity[i]][prs]++;
            if (i - 1 >= 0 && capacity[i] == 0 && capacity[i - 1] == 0) {
                ans--;
            }
        }
        return ans;
    }
};