class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int ty = 0, tn = 0;
        vector<int> py(n, 0), pn(n, 0);
        for (int i = 0; i < n; i++) {
            if (i - 1 >= 0) {
                py[i] = py[i - 1];
                pn[i] = pn[i - 1];
            }
            if (customers[i] == 'Y') {
                py[i]++;
                ty++;
            }
            if (customers[i] == 'N') {
                pn[i]++;
                tn++;
            }
        }
        int ans = 1e9;
        int minPen = 1e9;
        for (int i = 0; i < n; i++) {
            int pen = pn[i] + ty - py[i];
            if (customers[i] == 'Y') {
                pen++;
            } else {
                pen--;
            }
            if (pen < minPen) {
                ans = i;
                minPen = pen;
            }
        }
        if (tn < minPen) {
            ans = n;
        }
        return ans;
    }
};