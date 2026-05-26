class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lower_idx(26, -1), upper_idx(26, -1);
        for (int i = 0; i < word.size(); i++) {
            if (word[i] >= 'a' && word[i] <= 'z') {
                lower_idx[word[i] - 'a'] = i;
            } else if (word[i] >= 'A' && word[i] <= 'Z' && upper_idx[word[i] - 'A'] == -1) {
                upper_idx[word[i] - 'A'] = i;
            }
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (lower_idx[i] != -1 && upper_idx[i] != -1 && lower_idx[i] < upper_idx[i]) {
                ans++;
            }
        }
        return ans;
    }
};