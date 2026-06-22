class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> freq(26, 0);
        for (char& ch : text) {
            freq[ch - 'a']++;
        }
        int ans = 1e9;
        string str = "balon";
        for (char& ch : str) {
            if (ch == 'l' || ch == 'o') {
                ans = min(ans, freq[ch - 'a'] / 2);
            } else {
                ans = min(ans, freq[ch - 'a']);
            }
        }
        return ans;
    }
};