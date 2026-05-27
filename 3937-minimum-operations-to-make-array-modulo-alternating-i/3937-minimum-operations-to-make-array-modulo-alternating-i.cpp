class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 1e9;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (i == j) {
                    continue;
                }
                int x = i, y = j;
                int ops = 0;
                for (int l = 0; l < n; l++) {
                    int rem = nums[l] % k;
                    if (l & 1) {
                        ops += min((rem - y + k) % k, (y - rem + k) % k);
                    } else {
                        ops += min((rem - x + k) % k, (x - rem + k) % k);
                    }
                }
                ans = min(ans, ops);
            }
        }
        return ans;
    }
};