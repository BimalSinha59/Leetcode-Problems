class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        vector<long long> psum(n);
        psum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            psum[i] = psum[i - 1] + nums[i];
        }
        int good_cyclic_rotations = 0;
        for (int i = 0; i <= n / 2; i++) {
            long long left_sum = psum[i + n / 2 - 1] - (i - 1 >= 0 ? psum[i - 1] : 0);
            long long right_sum = psum[n - 1] - psum[i + n / 2 - 1] + (i - 1 >= 0 ? psum[i - 1] : 0);
            if (left_sum > right_sum) {
                good_cyclic_rotations++;
            }
        }
        for (int i = n / 2 + 1; i < n; i++) {
            long long left_sum = psum[n - 1] - psum[i - 1] + psum[i - n / 2 - 1];
            long long right_sum = psum[i - 1] - psum[i - n / 2 - 1];
            if (left_sum > right_sum) {
                good_cyclic_rotations++;
            }
        }
        return good_cyclic_rotations;
    }
};