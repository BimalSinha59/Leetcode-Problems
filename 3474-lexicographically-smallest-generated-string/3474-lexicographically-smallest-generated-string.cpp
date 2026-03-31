class Solution {
public:
    bool isSame(string& ans, string& str2, int idx, int m) {
        for (int j = idx; j < idx + m; j++) {
            if (ans[j] != str2[j - idx]) {
                return false;
            }
        }
        return true;
    }
    string generateString(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        int N = n + m - 1;
        string ans(N, '#');
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (ans[i + j] != '#' && ans[i + j] != str2[j]) {
                        return "";
                    }
                    ans[i + j] = str2[j];
                }
            }
        }
        vector<int> canChange(N, 0);
        for (int i = 0; i < N; i++) {
            if (ans[i] == '#') {
                ans[i] = 'a';
                canChange[i] = 1;
            }
        }
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                if (isSame(ans, str2, i, m)) {
                    bool flg = true;
                    for (int j = i + m - 1; j >= i; j--) {
                        if (canChange[j]) {
                            flg = false;
                            ans[j] = 'b';
                            break;
                        }
                    }
                    if (flg) {
                        return "";
                    }
                }
            }
        }
        return ans;
    }
};