class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<long long> etm(n, 0);
        vector<int> nom(n, 0);
        for (auto& meet : meetings) {
            long long mini = 1e18;
            int miniidx = -1;
            bool flg = true;
            for (int i = 0; i < n; i++) {
                if (etm[i] < mini) {
                    mini = etm[i];
                    miniidx = i;
                }
                if (etm[i] <= meet[0]) {
                    etm[i] = meet[1];
                    flg = false;
                    nom[i]++;
                    break;
                }
            }
            if (flg) {
                etm[miniidx] += 1LL * (meet[1] - meet[0]);
                nom[miniidx]++;
            }
        }
        int ans = 0;
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            if (nom[i] > maxi) {
                ans = i;
                maxi = nom[i];
            }
        }
        return ans;
    }
};