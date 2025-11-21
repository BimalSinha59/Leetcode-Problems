class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        unordered_map<char, int> mp1, mp2;
        for (int i = 0; i < n; i++) {
            if (mp1.count(s[i]) == 0) {
                mp1[s[i]] = i;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (mp2.count(s[i]) == 0) {
                mp2[s[i]] = i;
            }
        }
        int ans = 0;
        unordered_set<string> st;
        for (int i = 0; i < n; i++) {
            for (char ch = 'a'; ch <= 'z'; ch++) {
                string temp;
                if (mp1.count(ch) && mp1[ch] < i) {
                    temp.push_back(ch);
                }
                temp.push_back(s[i]);
                if (mp2[ch] > i) {
                    temp.push_back(ch);
                }
                if (temp.size() == 3 && st.find(temp) == st.end()) {
                    ans++;
                    st.insert(temp);
                }
            }
        }
        return ans;
    }
};