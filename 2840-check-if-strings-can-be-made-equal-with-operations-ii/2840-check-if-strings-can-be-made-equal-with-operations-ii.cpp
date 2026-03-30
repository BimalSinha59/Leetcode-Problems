class Solution {
public:
    bool checkStrings(string s1, string s2) {
        string str11, str12, str21, str22;
        int n = s1.size();
        for (int i = 0; i < n; i++) {
            if (i & 1) {
                str11.push_back(s1[i]);
                str21.push_back(s2[i]);
            } else {
                str12.push_back(s1[i]);
                str22.push_back(s2[i]);
            }
        }
        sort(str11.begin(), str11.end());
        sort(str12.begin(), str12.end());
        sort(str21.begin(), str21.end());
        sort(str22.begin(), str22.end());
        return str11 == str21 && str12 == str22;
    }
};