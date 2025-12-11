class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, vector<int>> mpx, mpy;
        for (auto& it : buildings) {
            mpx[it[0]].push_back(it[1]);
            mpy[it[1]].push_back(it[0]);
        }
        int ans = 0;
        for (auto& it : buildings) {
            int x = it[0], y = it[1];
            bool f1 = false, f2 = false;
            int mini = *min_element(mpx[x].begin(), mpx[x].end());
            int maxi = *max_element(mpx[x].begin(), mpx[x].end());
            if (y > mini && y < maxi) {
                f1 = true;
            }
            mini = *min_element(mpy[y].begin(), mpy[y].end());
            maxi = *max_element(mpy[y].begin(), mpy[y].end());
            if (x > mini && x < maxi) {
                f2 = true;
            }
            if (f1 && f2) {
                ans++;
            }
        }
        return ans;
    }
};