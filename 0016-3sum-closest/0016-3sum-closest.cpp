class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans;
        int mini = 1e9;
        for (int i = 0; i < n; i++) {
            int j = 0, k = n - 1;
            while (j < k) {
                if (i == j) {
                    j++;
                }
                if (i == k) {
                    k--;
                }
                if (j >= k) {
                    break;
                }
                int sum = nums[i] + nums[j] + nums[k];
                int diff = abs(target - sum);
                if (diff < mini) {
                    ans = sum;
                    mini = diff;
                }
                if (sum > target) {
                    k--;
                } else if (sum < target) {
                    j++;
                } else {
                    break;
                }
            }
            if (mini == 0) {
                break;
            }
        }
        return ans;
    }
};