class Solution {
public:
    long long solve(string& s, int& encCost, int& flatCost, int low, int high,
                    vector<int>& pos) {
        if (low == high) {
            return (s[low] == '0' ? flatCost : encCost);
        }
        int mid = (low + high) / 2;
        long long x = pos[high] - (low - 1 >= 0 ? pos[low - 1] : 0);
        int l = high - low + 1;
        long long ans1 = (x == 0 ? flatCost : 1LL * l * x * encCost);
        long long ans2 = LLONG_MAX;
        if (l % 2 == 0) {
            long long cost_left = solve(s, encCost, flatCost, low, mid, pos);
            long long cost_right = solve(s, encCost, flatCost, mid + 1, high, pos);
            ans2 = cost_left + cost_right;
        }
        return min(ans1, ans2);
    }
    long long minCost(string s, int encCost, int flatCost) {
        int n = s.size();
        vector<int> pos(n, 0);
        pos[0] = (s[0] == '0' ? 0 : 1);
        for (int i = 1; i < n; i++) {
            pos[i] = pos[i - 1] + (s[i] == '0' ? 0 : 1);
        }
        return solve(s, encCost, flatCost, 0, n - 1, pos);
    }
};