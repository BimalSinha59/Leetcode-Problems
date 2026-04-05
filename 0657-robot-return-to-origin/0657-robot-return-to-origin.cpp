class Solution {
public:
    bool judgeCircle(string moves) {
        int cnt1 = 0, cnt2 = 0;
        for (char& ch : moves) {
            if (ch == 'U') {
                cnt1++;
            } else if (ch == 'D') {
                cnt1--;
            } else if (ch == 'L') {
                cnt2++;
            } else {
                cnt2--;
            }
        }
        return cnt1 == 0 && cnt2 == 0;
    }
};