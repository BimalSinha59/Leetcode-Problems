class Solution {
public:
    string mergeCharacters(string s, int k) {
        unordered_map<char, int> mp;
        string ans;
        for (int i = 0; i < s.size(); i++) {
            if (mp.find(s[i]) == mp.end()) {
                ans.push_back(s[i]);
                mp[s[i]] = (int)ans.size() - 1;
            } else {
                int sz = ans.size();
                int dist = sz - mp[s[i]];
                if (dist > k) {
                    ans.push_back(s[i]);
                    mp[s[i]] = sz;
                }
            }
        }
        return ans;
    }
};