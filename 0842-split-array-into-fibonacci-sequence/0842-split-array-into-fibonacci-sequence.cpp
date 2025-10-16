class Solution {
public:
    bool f(string& num, int idx, vector<int>& ans, int n) {
        if (idx >= n && ans.size() >= 3) {
            return true;
        }
        int mxsz;
        if (num[idx] == '0') {
            mxsz = 1;
        } else {
            mxsz = 10;
        }

        for (int i = 1; i <= mxsz && i + idx <= n; i++) {
            string str = num.substr(idx, i);
            long long x = stoll(str);
            if (x > INT_MAX) {
                return false;
            }
            int m = ans.size();
            if (m >= 2 && ans[m - 1] * 1LL + ans[m - 2] < x) {
                return false;
            }
            if (m <= 1 || ans[m - 1] * 1LL + ans[m - 2] == x) {
                ans.push_back(x);
                if (f(num, idx + i, ans, n)) {
                    return true;
                }
                ans.pop_back();
            }
        }
        return false;
    }
    vector<int> splitIntoFibonacci(string num) {
        vector<int> ans;
        int n = num.size();
        f(num, 0, ans, n);
        return ans;
    }
};