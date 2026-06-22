class Solution {
public:
    int maxDistance(string moves) {
        int x = 0, y = 0;
        int cnt_s = 0;
        for (char& move : moves) {
            if (move == 'U') {
                y++;
            } else if (move == 'D') {
                y--;
            } else if (move == 'L') {
                x--;
            } else if (move == 'R') {
                x++;
            } else {
                cnt_s++;
            }
        }
        int maxManhattanDist = abs(x) + abs(y) + cnt_s;
        return maxManhattanDist;
    }
};