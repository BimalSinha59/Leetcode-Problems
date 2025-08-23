class Solution {
public:
    struct Box {
        int rmin = INT_MAX, rmax = INT_MIN, cmin = INT_MAX, cmax = INT_MIN,
            cnt = 0;
        void add(int r, int c) {
            rmin = min(rmin, r);
            rmax = max(rmax, r);
            cmin = min(cmin, c);
            cmax = max(cmax, c);
            cnt++;
        }
        bool valid() const { return cnt > 0; }
        long long area() const {
            if (!valid())
                return (long long)4e18;
            return 1LL * (rmax - rmin + 1) * (cmax - cmin + 1);
        }
    };

    static inline long long rangeArea(const vector<pair<int, int>>& ones,
                                      int rlo, int rhi, int clo, int chi) {
        Box b;
        for (auto [r, c] : ones) {
            if (rlo <= r && r <= rhi && clo <= c && c <= chi)
                b.add(r, c);
        }
        return b.area();
    }

    static inline long long bestTwoVertical(const vector<pair<int, int>>& ones,
                                            int rlo, int rhi, int m) {
        const long long INF = (long long)4e18;
        long long best = INF;
        for (int c = 0; c < m; ++c) {
            long long left = rangeArea(ones, rlo, rhi, 0, c);
            long long right = rangeArea(ones, rlo, rhi, c + 1, m - 1);
            if (left < INF && right < INF)
                best = min(best, left + right);
        }
        return best;
    }

    static inline long long
    bestTwoHorizontal(const vector<pair<int, int>>& ones, int clo, int chi,
                      int n) {
        const long long INF = (long long)4e18;
        long long best = INF;
        for (int r = 0; r < n; ++r) {
            long long top = rangeArea(ones, 0, r, clo, chi);
            long long bottom = rangeArea(ones, r + 1, n - 1, clo, chi);
            if (top < INF && bottom < INF)
                best = min(best, top + bottom);
        }
        return best;
    }

    long long minimumArea(vector<vector<int>>& grid) {
        const long long INF = (long long)4e18;
        int n = (int)grid.size(), m = (int)grid[0].size();

        vector<pair<int, int>> ones;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (grid[i][j])
                    ones.push_back({i, j});

        if (ones.empty()) {
            return 3;
        }

        {
            Box all;
            for (auto [r, c] : ones)
                all.add(r, c);
            long long best1 = all.area();
            long long best2 = INF;
            for (int c = 0; c < m; ++c) {
                long long L = rangeArea(ones, 0, n - 1, 0, c);
                long long R = rangeArea(ones, 0, n - 1, c + 1, m - 1);
                if (L < INF && R < INF)
                    best2 = min(best2, L + R);
            }
            for (int r = 0; r < n; ++r) {
                long long T = rangeArea(ones, 0, r, 0, m - 1);
                long long B = rangeArea(ones, r + 1, n - 1, 0, m - 1);
                if (T < INF && B < INF)
                    best2 = min(best2, T + B);
            }

            long long best3 = INF;
            for (int c1 = 0; c1 < m; ++c1)
                for (int c2 = c1 + 1; c2 < m; ++c2) {
                    long long a1 = rangeArea(ones, 0, n - 1, 0, c1);
                    long long a2 = rangeArea(ones, 0, n - 1, c1 + 1, c2);
                    long long a3 = rangeArea(ones, 0, n - 1, c2 + 1, m - 1);
                    if (a1 < INF && a2 < INF && a3 < INF)
                        best3 = min(best3, a1 + a2 + a3);
                }

            for (int r1 = 0; r1 < n; ++r1)
                for (int r2 = r1 + 1; r2 < n; ++r2) {
                    long long a1 = rangeArea(ones, 0, r1, 0, m - 1);
                    long long a2 = rangeArea(ones, r1 + 1, r2, 0, m - 1);
                    long long a3 = rangeArea(ones, r2 + 1, n - 1, 0, m - 1);
                    if (a1 < INF && a2 < INF && a3 < INF)
                        best3 = min(best3, a1 + a2 + a3);
                }

            for (int r = 0; r < n; ++r) {
                long long top1 = rangeArea(ones, 0, r, 0, m - 1);
                long long bot2 = bestTwoVertical(ones, r + 1, n - 1, m);
                if (top1 < INF && bot2 < INF)
                    best3 = min(best3, top1 + bot2);

                long long bot1 = rangeArea(ones, r + 1, n - 1, 0, m - 1);
                long long top2 = bestTwoVertical(ones, 0, r, m);
                if (bot1 < INF && top2 < INF)
                    best3 = min(best3, bot1 + top2);
            }

            for (int c = 0; c < m; ++c) {
                long long left1 = rangeArea(ones, 0, n - 1, 0, c);
                long long right2 = bestTwoHorizontal(ones, c + 1, m - 1, n);
                if (left1 < INF && right2 < INF)
                    best3 = min(best3, left1 + right2);

                long long right1 = rangeArea(ones, 0, n - 1, c + 1, m - 1);
                long long left2 = bestTwoHorizontal(ones, 0, c, n);
                if (right1 < INF && left2 < INF)
                    best3 = min(best3, right1 + left2);
            }

            long long ans = best3;
            if (best2 < INF)
                ans = min(ans, best2 + 1);
            ans = min(ans, best1 + 2);

            return ans;
        }
    }
    int minimumSum(vector<vector<int>>& grid) { 
        return minimumArea(grid); 
    }
};