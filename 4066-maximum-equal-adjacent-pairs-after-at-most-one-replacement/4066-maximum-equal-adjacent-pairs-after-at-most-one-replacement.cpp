class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n = nums.size();
        int prev_count = 0;
        int max_pair_count = 0;
        map<pair<int, int>, int> pair_count;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                prev_count++;
            } else {
                int mini = min(nums[i], nums[i + 1]);
                int maxi = max(nums[i], nums[i + 1]);
                pair_count[{mini, maxi}]++;
                max_pair_count = max(max_pair_count, pair_count[{mini, maxi}]);
            }
        }
        int ans = prev_count + max_pair_count;
        return ans;
    }
};