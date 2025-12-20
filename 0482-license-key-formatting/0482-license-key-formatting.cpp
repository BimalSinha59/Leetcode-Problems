class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int n = s.size();
        string ans;
        // int idx = 0;
        //  while (s[idx] != '-') {
        //      if (s[idx] >= 'a' && s[idx] <= 'z') {
        //          ans.push_back(toupper(s[idx]));
        //      } else {
        //          ans.push_back(s[idx]);
        //      }
        //      idx++;
        //  }
        string str;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] != '-') {
                if (s[i] >= 'a' && s[i] <= 'z') {
                    str.push_back(toupper(s[i]));
                } else {
                    str.push_back(s[i]);
                }
            }
            if (str.size() == k) {
                ans += str;
                if (i != 0) {
                    ans.push_back('-');
                }
                str.clear();
            }
        }
        if (!str.empty()) {
            ans += str;
        }
        while (!ans.empty() && ans.back() == '-') {
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};