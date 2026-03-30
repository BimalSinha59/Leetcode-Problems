class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();
        vector<int> mp(56, 0);
        for (int i = 0; i < n; i++) {
            int add = (i & 1) ? 26 : 0;
            mp[s1[i] - 'a' + add]++;
            mp[s2[i] - 'a' + add]--;
        }
        for (int i = 0; i < 56; i++) {
            if (mp[i]) {
                return false;
            }
        }
        return true;
    }
};