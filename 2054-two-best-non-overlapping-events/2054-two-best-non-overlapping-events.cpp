class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());
        int ans = 0;
        int mxVal = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;
                       
        for (int i = 0; i < n; i++) {
            int st = events[i][0];
            int et = events[i][1];
            int val = events[i][2];
            while (pq.size() && pq.top().first < st) {
                mxVal = max(mxVal, pq.top().second);
                pq.pop();
            }
            ans = max(ans, mxVal + val);
            pq.push({et, val});
        }
        return ans;
    }
};