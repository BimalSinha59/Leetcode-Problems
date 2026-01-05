class Solution {
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost,
                          int crossCost) {
        int n = s.size();
        int m1 = 0, m2 = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) {
                if (s[i] < t[i]) {
                    m1++;
                } else {
                    m2++;
                }
            }
        }
        int pairs = min(m1, m2);
        int rem = abs(m1 - m2);
        long long cost1 = pairs * min(2LL * flipCost, 1LL * swapCost);
        long long cost2 = (rem / 2) * min(2LL * flipCost, 1LL * (swapCost + crossCost));
        long long cost3 = 0;
        if (rem & 1) {
            cost3 = flipCost;
        }
        return cost1 + cost2 + cost3;
    }
};