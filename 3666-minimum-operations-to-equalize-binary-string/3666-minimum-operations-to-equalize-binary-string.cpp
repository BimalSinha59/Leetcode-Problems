class Solution {
public:
    int minOperations(string s, int k) {
        long long n = (long long)s.size();
        long long z = 0;
        for (char c : s)
            z += (c == '0');
        if (z == 0)
            return 0;

        if (k == (int)n)
            return (z == n) ? 1 : -1;
        if ((k % 2 == 0) && (z % 2 == 1))
            return -1;

        auto ok = [&](long long t) -> bool {
            long long total = t * (long long)k;
            if ((total & 1LL) != (z & 1LL))
                return false;

            long long oMax = (t & 1LL) ? t : (t - 1);
            long long eMax = (t & 1LL) ? (t - 1) : t;
            if (oMax < 1)
                return false;

            long long o = n - z;

            long long L = max(z, total - o * eMax);
            long long R = min(z * oMax, total);
            if (L > R)
                return false;

            if ((L & 1LL) != (z & 1LL))
                L++;
            return L <= R;
        };

        long long t = (z + k - 1LL) / k;
        if (t < 1)
            t = 1;

        long long upr = 2 * n + 5;

        if (k % 2 == 1) {
            if ((t & 1LL) != (z & 1LL))
                t++;
            for (; t <= upr; t += 2)
                if (ok(t))
                    return (int)t;
        } else {
            for (; t <= upr; t++)
                if (ok(t))
                    return (int)t;
        }

        return -1;
    }
};