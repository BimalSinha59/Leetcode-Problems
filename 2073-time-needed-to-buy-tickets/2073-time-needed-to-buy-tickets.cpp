class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int, int>> q;
        int n = tickets.size();
        for (int i = 0; i < n; i++) {
            q.push({tickets[i], i});
        }
        int ans = 0;
        while (!q.empty()) {
            ans++;
            int fp = q.front().first;
            int idx = q.front().second;
            if (idx == k && fp == 1) {
                return ans;
            }
            q.pop();
            if (fp != 1) {
                q.push({fp - 1, idx});
            }
        }
        return 0;
    }
};