class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int ans = 0;
        vector<int> v;
        int idx;
        for (int i = 0; i < m; i++) {
            bool flg = true;
            v.clear();
            idx = 0;
            for (int j = 0; j < n; j++) {
                if (j != 0) {
                    if (strs[j][i] < strs[j - 1][i]) {
                        ans++;
                        flg = false;
                        break;
                    }
                    if (strs[j][i] == strs[j - 1][i]) {
                        v.push_back(j);
                        idx = i;
                    }
                }
            }
            if (flg) {
                break;
            }
        }
        for (int i = idx + 1; i < m; i++) {
            vector<int> temp;
            bool flg = true;
            for (int j = 0; j < v.size(); j++) {
                if (strs[v[j]][i] < strs[v[j] - 1][i]) {
                    flg = false;
                    break;
                } else if (strs[v[j]][i] == strs[v[j] - 1][i]) {
                    temp.push_back(v[j]);
                }
            }
            if (flg && temp.empty()) {
                return ans;
            } else if (flg && !temp.empty()) {
                v = temp;
            } else {
                ans++;
            }
        }
        return ans;
    }
};