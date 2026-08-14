class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        vector<int> freq(26, 0);
        int left = 0, maxLen = 0, maxFreq = 0;
        char maxFreqChar;
        for (int right = 0; right < n; right++) {
            freq[s[right] - 'a']++;
            if (freq[s[right] - 'a'] > maxFreq) {
                maxFreq = freq[s[right] - 'a'];
                maxFreqChar = s[right];
            }
            while (maxFreq > 2) {
                freq[s[left] - 'a']--;
                if (s[left] == maxFreqChar) {
                    maxFreq--;
                }
                left++;
            }
            int len = right - left + 1;
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};