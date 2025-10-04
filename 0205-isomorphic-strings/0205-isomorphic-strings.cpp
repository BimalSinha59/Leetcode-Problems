class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        unordered_map<char, char> mp1,mp2;
        for (int i = 0; i < n; i++) {
            if (mp1.find(s[i]) != mp1.end() && t[i] != mp1[s[i]]) {
                return false;
            }
            mp1[s[i]] = t[i];
        }
         for (int i = 0; i < n; i++) {
            if (mp2.find(t[i]) != mp2.end() && s[i] != mp2[t[i]]) {
                return false;
            }
            mp2[t[i]] = s[i];
        }
        return true;
    }
};