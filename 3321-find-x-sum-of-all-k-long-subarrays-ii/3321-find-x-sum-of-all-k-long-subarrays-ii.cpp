class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<long long> ans(n - k + 1);
        unordered_map<int, int> mp;
        auto cmp = [&](int a, int b) {
            if (mp[a] != mp[b]) {
                return mp[a] < mp[b];
            }
            return a < b;
        };

        set<int, decltype(cmp)> tpx(cmp), rst(cmp);
        long long smtp = 0;

        auto rebalance = [&]() {
            while ((int)tpx.size() < min(x, (int)mp.size()) && !rst.empty()) {
                int best = *prev(rst.end());
                rst.erase(prev(rst.end()));
                tpx.insert(best);
                smtp += 1LL * mp[best] * best;
            }

            while ((int)tpx.size() > x) {
                int worst = *tpx.begin();
                tpx.erase(tpx.begin());
                rst.insert(worst);
                smtp -= 1LL * mp[worst] * worst;
            }

            while (!tpx.empty() && !rst.empty()) {
                int worstTop = *tpx.begin();
                int bestRest = *prev(rst.end());
                int fw = mp[worstTop], fr = mp[bestRest];

                if (fr > fw || (fr == fw && bestRest > worstTop)) {
                    tpx.erase(tpx.begin());
                    rst.erase(prev(rst.end()));
                    tpx.insert(bestRest);
                    rst.insert(worstTop);
                    smtp += 1LL * fr * bestRest - 1LL * fw * worstTop;
                } else {
                    break;
                }
            }
        };
        for (int i = 0; i < n; ++i) {
            int v = nums[i];
            int old = mp[v];

            if (old > 0) {
                if (tpx.erase(v)) {
                    smtp -= 1LL * old * v;
                } else {
                    rst.erase(v);
                }
            }

            mp[v] = old + 1;
            rst.insert(v);
            rebalance();

            if (i >= k) {
                int u = nums[i - k];
                int oldU = mp[u];

                if (tpx.erase(u)) {
                    smtp -= 1LL * oldU * u;
                } else {
                    rst.erase(u);
                }

                if (oldU == 1) {
                    mp.erase(u);
                } else {
                    mp[u] = oldU - 1;
                    rst.insert(u);
                }
                rebalance();
            }

            if (i >= k - 1) {
                ans[i - k + 1] = smtp;
            }
        }
        return ans;
    }
};