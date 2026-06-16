class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n2 = nums.size();
        int n = n2 / 2;
        int total_sum = 0;
        for (int num : nums)
            total_sum += num;

        vector<vector<int>> left_sums(n + 1);
        vector<vector<int>> right_sums(n + 1);

        for (int i = 0; i < (1 << n); ++i) {
            int count = 0;
            int sum = 0;
            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) {
                    count++;
                    sum += nums[j];
                }
            }
            left_sums[count].push_back(sum);
        }

        for (int i = 0; i < (1 << n); ++i) {
            int count = 0;
            int sum = 0;
            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) {
                    count++;
                    sum += nums[n + j];
                }
            }
            right_sums[count].push_back(sum);
        }

        for (int i = 0; i <= n; ++i) {
            sort(right_sums[i].begin(), right_sums[i].end());
        }

        int min_diff = INT_MAX;
        int target = total_sum / 2;

        for (int k = 0; k <= n; ++k) {
            for (int l_sum : left_sums[k]) {
                int r_target = target - l_sum;
                auto& r_list = right_sums[n - k];

                auto it = lower_bound(r_list.begin(), r_list.end(), r_target);

                if (it != r_list.end()) {
                    int s1 = l_sum + *it;
                    int s2 = total_sum - s1;
                    min_diff = min(min_diff, abs(s1 - s2));
                }
                if (it != r_list.begin()) {
                    int s1 = l_sum + *prev(it);
                    int s2 = total_sum - s1;
                    min_diff = min(min_diff, abs(s1 - s2));
                }
            }
        }

        return min_diff;
    }
};