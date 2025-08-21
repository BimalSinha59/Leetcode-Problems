class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> hgt(m, 0);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            vector<int> sum(m, 0);
            stack<int> st;
            for (int j = 0; j < m; j++) {
                hgt[j] = (mat[i][j] == 0) ? 0 : hgt[j] + 1;
                while (!st.empty() && hgt[st.top()] >= hgt[j]) {
                    st.pop();
                }
                if (!st.empty()) {
                    int psi = st.top();
                    sum[j] = sum[psi] + hgt[j] * (j - psi);
                } else {
                    sum[j] = hgt[j] * (j + 1);
                }
                st.push(j);
                ans += sum[j];
            }
        }
        return ans;
    }
};