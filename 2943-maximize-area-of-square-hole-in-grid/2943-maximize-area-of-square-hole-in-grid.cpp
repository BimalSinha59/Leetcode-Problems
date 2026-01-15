class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars,
                               vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int i = 0, j = 0;
        int cnt = 1;
        int maxhbs = 1;
        for (int i = 1; i < hBars.size(); i++) {
            if (hBars[i] == hBars[i - 1] + 1) {
                cnt++;
                maxhbs = max(maxhbs, cnt);
            } else {
                cnt = 1;
            }
        }
        cnt = 1;
        int maxvbs = 1;
        for (int i = 1; i < vBars.size(); i++) {
            if (vBars[i] == vBars[i - 1] + 1) {
                cnt++;
                maxvbs = max(maxvbs, cnt);
            } else {
                cnt = 1;
            }
        }
        int temp = min(maxhbs, maxvbs) + 1;
        int ans = temp * temp;
        return ans;
    }
};