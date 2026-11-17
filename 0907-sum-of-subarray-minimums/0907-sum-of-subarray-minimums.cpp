class Solution {
public:
    vector<int> find_prev_smallernequal(vector<int>& arr, int n) {
        vector<int> ans(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
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

    vector<int> find_next_smaller(vector<int>& arr, int n) {
        vector<int> ans(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                ans[i] = n;
            } else {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        auto psee = find_prev_smallernequal(arr, n);
        auto nse = find_next_smaller(arr, n);
        int sum_of_mins = 0;
        int mod = (int)(1e9 + 7);
        for (int i = 0; i < n; i++) {
            int left = i - psee[i];
            int right = nse[i] - i;
            sum_of_mins = (sum_of_mins + (1LL * left * right * arr[i]) % mod) % mod;
        }
        return sum_of_mins;
    }
};