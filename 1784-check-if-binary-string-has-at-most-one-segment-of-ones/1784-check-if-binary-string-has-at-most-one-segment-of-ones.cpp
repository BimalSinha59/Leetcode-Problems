class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        int cnt = 0;
        int i = 0, j = n - 1;
        while (s[i] == '1' && s[j] == '1' && i < j) {
            i++;
            j--;
        }
        if (i < j && i != 0 && j != n - 1) {
            return false;
        }
        for (int i = 1; i < n; i++) {
            if ((s[i - 1] == '0' && s[i] == '1') ||
                (s[i - 1] == '1' && s[i] == '0')) {
                cnt++;
            }
        }
        return cnt <= 2;
    }
};