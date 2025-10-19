class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();
        unordered_set<string> st;
        string ans = s;
        queue<string> q;
        q.push(s);
        st.insert(s);
        while (!q.empty()) {
            string curr = q.front();
            q.pop();
            if (curr < ans) {
                ans = curr;
            }
            string ns1 = curr;
            for (int i = 1; i < n; i += 2) {
                ns1[i] = (((curr[i] - '0') + a) % 10 + '0');
            }
            if (st.count(ns1) == 0) {
                q.push(ns1);
                st.insert(ns1);
            }
            string ns2 = curr.substr(n - b) + curr.substr(0, n - b);
            if (st.count(ns2) == 0) {
                q.push(ns2);
                st.insert(ns2);
            }
        }
        return ans;
    }
};