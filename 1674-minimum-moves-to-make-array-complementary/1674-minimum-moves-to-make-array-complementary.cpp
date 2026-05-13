class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> diff(2 * limit + 2, 0);
        for (int i = 0; i < n / 2; i++) {
            int a = min(nums[i], nums[n - 1 - i]);
            int b = max(nums[i], nums[n - 1 - i]);

            diff[2] += 2;
            diff[2 * limit + 1] -= 2;

            diff[a + 1] -= 1;
            diff[b + limit + 1] += 1;

            diff[a + b] -= 1;
            diff[a + b + 1] += 1;
        }

        int ans = 1e9;
        int current_moves = 0;
        for (int i = 2; i <= 2 * limit; i++) {
            current_moves += diff[i];
            ans = min(ans, current_moves);
        }
        return ans;
    }
};