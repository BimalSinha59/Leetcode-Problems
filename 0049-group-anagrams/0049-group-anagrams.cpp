class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, int> mp;
        int idx = 0;
        vector<vector<string>> ans(n);
        for (int i = 0; i < n; i++) {
            string str = strs[i];
            string nstr = str;
            sort(nstr.begin(), nstr.end());
            if (mp.find(nstr) == mp.end()) {
                ans[idx].push_back(str);
                mp[nstr] = idx;
                idx++;
            } else {
                int ind = mp[nstr];
                ans[ind].push_back(str);
            }
        }
        while (!ans.empty() && ans.back().empty()) {
            ans.pop_back();
        }
        return ans;
    }
};