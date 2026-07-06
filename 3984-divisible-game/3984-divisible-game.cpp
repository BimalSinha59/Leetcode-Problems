class Solution {
public:
    int divisibleGame(vector<int>& nums) {
        int n = nums.size();
        set<int> st;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j * j <= nums[i]; j++) {
                if (nums[i] % j == 0) {
                    if (j > 1) {
                        st.insert(j);
                    }
                    if (nums[i] / j > 1) {
                        st.insert(nums[i] / j);
                    }
                }
            }
        }
        int kf = 2;
        while (st.count(kf)) {
            kf++;
        }
        st.insert(kf);
        int maxi = INT_MIN;
        int k = -1;
        for (auto& it : st) {
            int sum = 0, mx = INT_MIN;
            for (int i = 0; i < n; i++) {
                int ss;
                if (nums[i] % it == 0) {
                    ss = nums[i];
                } else {
                    ss = -nums[i];
                }
                sum = max(ss, sum + ss);
                mx = max(mx, sum);
            }
            if (mx > maxi) {
                maxi = mx;
                k = it;
            }
        }
        int md = 1e9 + 7;
        int ans = ((1LL * maxi % md) * (k % md)) % md;
        if (ans < 0)
            ans = (ans % md + md) % md;
        return ans;
    }
};