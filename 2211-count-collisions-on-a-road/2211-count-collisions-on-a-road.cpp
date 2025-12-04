class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int s = n, e = -1;
        for (int i = 0; i < n; i++) {
            if (directions[i] == 'R' || directions[i] == 'S') {
                s = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (directions[i] == 'L' || directions[i] == 'S') {
                e = i;
                break;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (directions[i] == 'L' && i > s) {
                ans++;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (directions[i] == 'R' && i < e) {
                ans++;
            }
        }
        return ans;
    }
};