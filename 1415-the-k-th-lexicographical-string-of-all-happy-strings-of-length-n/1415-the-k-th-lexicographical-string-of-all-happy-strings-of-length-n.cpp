class Solution {
public:
    void solve(int n, int& k, int& cnt, string& curr, string& ans) {
        if (curr.size() == n) {
            cnt++;
            if (cnt == k) {
                ans = curr;
            }
            return;
        }
        for (char ch = 'a'; ch <= 'c'; ch++) {
            if (!curr.empty() && curr.back() == ch) {
                continue;
            }
            curr.push_back(ch);
            solve(n, k, cnt, curr, ans);
            curr.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        string ans = "";
        int cnt = 0;
        string curr = "";
        solve(n, k, cnt, curr, ans);
        return ans;
    }
};