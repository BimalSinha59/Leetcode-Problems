class Solution {
public:
    vector<int> nge(vector<int>& arr, int n) {
        vector<int> ans(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                ans[i] = -1;
            } else {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> v = nge(temperatures, n);
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            if (v[i] == -1) {
                ans[i] = 0;
            } else {
                ans[i] = v[i] - i;
            }
        }
        return ans;
    }
};