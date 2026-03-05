class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        map<int, int> mp;
        for (int& num : nums) {
            mp[num]++;
        }
        vector<pair<int, int>> v;
        for (auto it : mp) {
            v.push_back({it.first, it.second});
        }
        for (int i = 1; i < v.size(); i++) {
            if (v[i].second != v[0].second) {
                return {v[0].first, v[i].first};
            }
        }
        return {-1, -1};
    }
};