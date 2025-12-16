class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        stack<int> st;
        int ptime = 0;
        for (int i = 0; i < logs.size(); i++) {
            int idx1 = -1, idx2 = -1;
            for (int j = 0; j < logs[i].size(); j++) {
                if (logs[i][j] == ':') {
                    if (idx1 == -1) {
                        idx1 = j;
                    } else {
                        idx2 = j;
                    }
                }
            }
            int id = stoi(logs[i].substr(0, idx1));
            string ft = logs[i].substr(idx1 + 1, idx2 - idx1 - 1);
            int ctime =
                stoi(logs[i].substr(idx2 + 1, logs[i].size() - idx2 - 1));
            if (ft == "start") {
                if (!st.empty()) {
                    ans[st.top()] += ctime - ptime;
                }
                st.push(id);
                ptime = ctime;
            } else {
                ans[st.top()] += ctime - ptime + 1;
                st.pop();
                ptime = ctime + 1;
            }
        }
        return ans;
    }
};