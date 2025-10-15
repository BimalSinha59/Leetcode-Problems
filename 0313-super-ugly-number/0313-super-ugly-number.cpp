class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<vector<long long>, vector<vector<long long>>,
                       greater<vector<long long>>>pq;

        for (int it : primes) {
            pq.push({it, it, 0});
        }

        vector<long long> ans(n);
        ans[0] = 1;
        int i = 1;

        while (i < n) {
            auto it = pq.top();
            pq.pop();

            long long ele = it[0], pm = it[1], idx = it[2];
            if (ele != ans[i - 1]) {
                ans[i] = ele;
                i++;
            }

            pq.push({pm * ans[idx + 1], pm, idx + 1});
        }

        return (int)ans[n - 1];
    }
};