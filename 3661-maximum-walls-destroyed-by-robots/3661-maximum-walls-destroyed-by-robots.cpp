class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        if (n == 0) return 0;

        sort(walls.begin(), walls.end());

        vector<pair<int,int>> v;
        for(int i = 0; i < n; i++){
             v.push_back({robots[i], distance[i]});
        }
        sort(v.begin(), v.end());
        vector<vector<long long>> ivls(n, vector<long long>(4));

        for(int i = 0; i < n; i++){
            long long pos = v[i].first;
            long long d = v[i].second;
            long long lblock = (i > 0 ? v[i-1].first : LLONG_MIN);
            long long rblock = (i < n - 1 ? v[i+1].first : LLONG_MAX);
            ivls[i][0] = max(pos - d, lblock);
            ivls[i][1] = pos;
            ivls[i][2] = pos;
            ivls[i][3] = min(pos + d, rblock);
        }

        auto getCount = [&](long long l, long long r){
            if (l > r) return 0; 
            auto it1 = lower_bound(walls.begin(), walls.end(), l);
            auto it2 = upper_bound(walls.begin(), walls.end(), r);
            return (int)(it2 - it1);
        };
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = getCount(ivls[0][0], ivls[0][1]);
        dp[0][1] = getCount(ivls[0][2], ivls[0][3]);
        for(int i = 1; i < n; i++){
            long long l1 = ivls[i][0], r1 = ivls[i][1];
            long long l2 = ivls[i][2], r2 = ivls[i][3];

            long long prl = ivls[i-1][1];
            long long prr = ivls[i-1][3];
            int laddl = getCount(max(l1, prl + 1), r1);
            int laddr = getCount(max(l1, prr + 1), r1);

            dp[i][0] = max(dp[i-1][0] + laddl, dp[i-1][1]+ laddr);
            int raddl = getCount(max(l2, prl + 1), r2);
            int raddr = getCount(max(l2, prr + 1), r2);
            dp[i][1] = max(dp[i-1][0] + raddl,dp[i-1][1] + raddr );
        }
        return max(dp[n-1][0], dp[n-1][1]);
    }
};