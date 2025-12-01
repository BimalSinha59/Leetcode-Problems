class Solution {
public:
    bool pdctfun(long long time, vector<int>& batteries, int n) {
        long long sum = 0;
        for (int& it : batteries) {
            sum += min(time, 1LL * it);
            if (sum >= n * 1LL * time) {
                return true;
            }
        }
        return sum >= n * 1LL * time;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long long tot = 0;
        for (int& it : batteries) {
            tot += it;
        }
        long long s = 0, e = tot / n;
        long long ans = 0;
        while (s <= e) {
            long long mid = s + (e - s) / 2;
            if (pdctfun(mid, batteries, n)) {
                ans = mid;
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return ans;
    }
};