class Solution {
public:
    void dfs(int num, int n, vector<int>& ans) {
        if (num > n) {
            return;
        }
        ans.push_back(num);
        for (int d = 0; d <= 9; d++) {
            int nnum = num * 10 + d;
            if (nnum <= n) {
                dfs(nnum, n, ans);
            } else {
                break;
            }
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for (int i = 1; i <= 9; i++) {
            dfs(i, n, ans);
        }
        return ans;
    }
};