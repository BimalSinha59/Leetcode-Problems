class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        unordered_map<char, int> mp;
        for (char& ch : t) {
            mp[ch]++;
        }
        int left = 0, startIdx = -1, minLen = 1e9, cnt = 0;
        for (int right = 0; right < m; right++) {
            if (mp[s[right]] > 0) {
                cnt++;
            }
            mp[s[right]]--;
            while (cnt == n) {
                int len = right - left + 1;
                if (len < minLen) {
                    startIdx = left;
                    minLen = len;
                }
                mp[s[left]]++;
                if (mp[s[left]] > 0) {
                    cnt--;
                }
                left++;
            }
        }
        return startIdx == -1 ? "" : s.substr(startIdx, minLen);
    }
};