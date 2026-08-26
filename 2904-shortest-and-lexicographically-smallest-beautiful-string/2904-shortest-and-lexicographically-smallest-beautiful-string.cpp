class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int min_len = 1e9;
        string smallest_str = "";
        int left = 0;
        int cnt = 0;
        for (int right = 0; right < n; right++) {
            if (s[right] == '1') {
                cnt++;
            }
            while (cnt > k) {
                if (s[left] == '1') {
                    cnt--;
                }
                left++;
            }
            if (cnt == k) {
                while (left < right && s[left] == '0') {
                    left++;
                }
                int len = right - left + 1;
                string str = s.substr(left, len);
                if (min_len == 1e9) {
                    min_len = len;
                    smallest_str = str;
                } else if (len < min_len) {
                    min_len = len;
                    smallest_str = str;
                } else if (len == min_len && str < smallest_str) {
                    smallest_str = str;
                }
            }
        }
        return smallest_str;
    }
};