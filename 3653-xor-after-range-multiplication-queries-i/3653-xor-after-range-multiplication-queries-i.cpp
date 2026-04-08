class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        for (auto& q : queries) {
            for (int i = q[0]; i <= q[1]; i += q[2]) {
                nums[i] = (1LL * nums[i] * q[3]) % MOD;
            }
        }
        int ans = 0;
        for (int& num : nums) {
            ans ^= num;
        }
        return ans;
    }
};