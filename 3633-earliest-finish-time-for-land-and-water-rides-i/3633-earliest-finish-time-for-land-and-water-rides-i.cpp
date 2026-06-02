class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int ls_mini = 1e9;
        for (int i = 0; i < n; i++) {
            ls_mini = min(ls_mini, landStartTime[i] + landDuration[i]);
        }
        int ans1 = 1e9;
        for (int i = 0; i < m; i++) {
            if (waterStartTime[i] <= ls_mini) {
                ans1 = min(ans1, ls_mini + waterDuration[i]);
            } else {
                ans1 = min(ans1, waterStartTime[i] + waterDuration[i]);
            }
        }
        int ws_mini = 1e9;
        for (int i = 0; i < m; i++) {
            ws_mini = min(ws_mini, waterStartTime[i] + waterDuration[i]);
        }
        int ans2 = 1e9;
        for (int i = 0; i < n; i++) {
            if (landStartTime[i] <= ws_mini) {
                ans2 = min(ans2, ws_mini + landDuration[i]);
            } else {
                ans2 = min(ans2, landStartTime[i] + landDuration[i]);
            }
        }
        return min(ans1, ans2);
    }
};