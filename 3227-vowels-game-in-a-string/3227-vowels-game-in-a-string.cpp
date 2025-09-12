class Solution {
public:
    bool doesAliceWin(string s) {

        int n = s.length();

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u') {
                count++;
            }
        }

        if (count >= 1) {
            return true;
        }
        return false;
    }
};