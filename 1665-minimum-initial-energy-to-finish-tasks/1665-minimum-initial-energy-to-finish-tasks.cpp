class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size();
        sort(tasks.begin(), tasks.end(), [](vector<int>& a, vector<int>& b) {
            int diff1 = a[1] - a[0];
            int diff2 = b[1] - b[0];
            if (diff1 == diff2) {
                return a[0] > b[0];
            }
            return diff1 > diff2;
        });

        int ans = tasks[0][1];
        int add = tasks[0][1] - tasks[0][0];
        for (int i = 1; i < n; i++) {
            int nadd = max(0, tasks[i][1] - add);
            ans += nadd;
            add += nadd;
            add -= tasks[i][0];
        }
        return ans;
    }
};