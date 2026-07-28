class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        vector<int> freq(26, 0);
        for (char& ch : s) {
            freq[ch - 'a']++;
        }
        string ans(n, '*');
        int i = 0, j = n - 1;
        for (char ch = 'a'; ch <= 'z'; ch++) {
            int char_freq = freq[ch - 'a'];
            if (char_freq & 1) {
                ans[n / 2] = ch;
                char_freq--;
            }
            while (char_freq) {
                ans[i] = ch;
                ans[j] = ch;
                char_freq -= 2;
                i++;
                j--;
            }
        }
        return ans;
    }
};