class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> st;
        for (auto& obs : obstacles) {
            string key = to_string(obs[0]) + "_" + to_string(obs[1]);
            st.insert(key);
        }
        int x = 0, y = 0;
        pair<int, int> dir = {0, 1};
        int ans = 0;
        for (auto& com : commands) {
            if (com == -2) {
                dir = {-dir.second, dir.first};
            } else if (com == -1) {
                dir = {dir.second, -dir.first};
            } else {
                for (int i = 0; i < com; i++) {
                    int newx = x + dir.first;
                    int newy = y + dir.second;
                    string newKey = to_string(newx) + "_" + to_string(newy);
                    if (st.find(newKey) != st.end()) {
                        break;
                    }
                    x = newx;
                    y = newy;
                }
            }
            ans = max(ans, x * x + y * y);
        }
        return ans;
    }
};