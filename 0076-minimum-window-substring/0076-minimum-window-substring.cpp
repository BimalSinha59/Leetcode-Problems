class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        int freq[256] = {0};
        for (char& ch : t) {
            freq[ch]++;
        }
        int left = 0, startIdx = -1, minLen = 1e9, cnt = 0;
        for (int right = 0; right < m; right++) {
            if (freq[s[right]] > 0) {
                cnt++;
            }
            freq[s[right]]--;
            while (cnt == n) {
                int len = right - left + 1;
                if (len < minLen) {
                    startIdx = left;
                    minLen = len;
                }
                freq[s[left]]++;
                if (freq[s[left]] > 0) {
                    cnt--;
                }
                left++;
            }
        }
        return startIdx == -1 ? "" : s.substr(startIdx, minLen);
    }
};