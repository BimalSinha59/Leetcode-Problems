class Solution {
public:
    vector<int> computeLPS(string& pattern) {
        int n = pattern.size();
        vector<int> lps(n, 0);
        int len = 0;
        int i = 1;
        while (i < n) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    bool KMP(string& word, string& pattern) {
        vector<int> lps = computeLPS(pattern);
        int i = 0;
        int j = 0;
        while (i < word.size()) {
            if (word[i] == pattern[j]) {
                i++;
                j++;
            }
            if (j == pattern.size()) {
                return true;
            } else if (i < word.size() && word[i] != pattern[j]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return false;
    }
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        for (string& pattern : patterns) {
            if (KMP(word, pattern)) {
                ans++;
            }
        }
        return ans;
    }
};