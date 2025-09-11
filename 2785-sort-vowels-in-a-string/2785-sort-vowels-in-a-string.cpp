class Solution {
public:
    string sortVowels(string s) {
        string ans = s;
        string str;
        for (auto it : s) {
            if (it == 'a' || it == 'e' || it == 'i' || it == 'o' || it == 'u' ||
                it == 'A' || it == 'E' || it == 'I' || it == 'O' || it == 'U') {
                str.push_back(it);
            }
        }
        sort(str.begin(), str.end());
        int j = 0;
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' ||
                ans[i] == 'o' || ans[i] == 'u' || ans[i] == 'A' ||
                ans[i] == 'E' || ans[i] == 'I' || ans[i] == 'O' ||
                ans[i] == 'U') {
                ans[i] = str[j];
                j++;
            }
        }
        return ans;
    }
};