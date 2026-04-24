class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int countL = 0, countR = 0, count_ = 0;
        for (char& ch : moves) {
            if (ch == 'L') {
                countL++;
            } else if (ch == 'R') {
                countR++;
            } else {
                count_++;
            }
        }
        return max(countL + count_ - countR, countR + count_ - countL);
    }
};