class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        unordered_map<char, int> mp;
        for (auto it : s1) {
            mp[it]++;
        }
        unordered_map<char, int> mp1 = mp;
        for (int i = 0; i < n && i < m; i++) {
            if (mp1.find(s2[i]) != mp1.end()) {
                mp[s2[i]]--;
                if (mp[s2[i]] == 0) {
                    mp.erase(s2[i]);
                }
            }
        }
        if (mp.empty()) {
            return true;
        }
        for (int i = n; i < m; i++) {
            if (mp1.find(s2[i - n]) != mp1.end()) {
                mp[s2[i - n]]++;
                if (mp[s2[i - n]] == 0) {
                    mp.erase(s2[i - n]);
                }
            }
            if (mp1.find(s2[i]) != mp1.end()) {
                mp[s2[i]]--;
                if (mp[s2[i]] == 0) {
                    mp.erase(s2[i]);
                }
            }
            if (mp.empty()) {
                return true;
            }
        }
        return false;
    }
};