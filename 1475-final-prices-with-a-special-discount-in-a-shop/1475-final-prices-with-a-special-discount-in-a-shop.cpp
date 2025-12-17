class Solution {
public:
    vector<int> nse(vector<int>& arr, int n) {
        vector<int> ans(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() > arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                ans[i] = -1;
            } else {
                ans[i] = st.top();
            }
            st.push(arr[i]);
        }
        return ans;
    }
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> v = nse(prices, n);
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (v[i] == -1) {
                ans.push_back(prices[i]);
            } else {
                ans.push_back(prices[i] - v[i]);
            }
        }
        return ans;
    }
};