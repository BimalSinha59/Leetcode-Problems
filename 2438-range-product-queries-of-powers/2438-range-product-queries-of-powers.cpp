class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> v;
        for (int i = 0; i < 32; i++) {
            if ((n & (1 << i))) {
                v.push_back(1 << i);
            }
        }
        int mod = 1e9 + 7;
        vector<int> ans;
        for (auto it : queries) {
            int l = it[0];
            int r = it[1];
            int res = 1;
            for (int i = l; i <= r; i++) {
                res = (res * 1LL * v[i]) % mod;
            }
            ans.push_back(res);
        }
        return ans;
    }
};