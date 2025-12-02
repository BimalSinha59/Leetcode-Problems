class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<int, int> mp;
        for (auto it : points) {
            mp[it[1]]++;
        }
        vector<int> v;
        for (auto it : mp) {
            if (it.second > 1) {
                v.push_back(it.second);
            }
        }
        int mod = 1e9 + 7;
        int m = v.size();
        int ans = 0;
        if (m > 1) {
            long long nsum[m];
            long long x = v[m - 1];
            nsum[m - 1] = x * (x - 1) / 2;
            for (int i = m - 2; i >= 0; i--) {
                x = v[i];
                nsum[i] = nsum[i + 1] + (x * (x - 1) / 2);
            }
            for (int i = 0; i < m - 1; i++) {
                x = v[i];
                long long y = x * (x - 1) / 2;
                ans = (ans + ((y % mod) * (nsum[i + 1] % mod)) % mod) % mod;
            }
        }
        return ans;
    }
};