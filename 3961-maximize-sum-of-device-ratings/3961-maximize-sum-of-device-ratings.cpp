class Solution {
public:
    pair<int, int> find_min_elements(vector<int>& nums, int& m) {
        if (m == 1) {
            return {nums[0], nums[0]};
        }
        int first_mini = 1e9;
        int second_mini = 1e9;
        for (int i = 0; i < m; i++) {
            if (nums[i] < first_mini) {
                second_mini = first_mini;
                first_mini = nums[i];
            } else if (nums[i] < second_mini && nums[i] >= first_mini) {
                second_mini = nums[i];
            }
        }
        return {first_mini, second_mini};
    }
    long long maxRatings(vector<vector<int>>& units) {
        int n = units.size();
        int m = units[0].size();
        long long sum = 0;
        int smallest = 1e9;
        int min_second = 1e9;
        for (auto& unit : units) {
            auto it = find_min_elements(unit, m);
            sum += it.second;
            smallest = min(smallest, it.first);
            min_second = min(min_second, it.second);
        }
        if (m == 1) {
            return sum;
        }
        long long rating_sum = sum + smallest - min_second;
        return rating_sum;
    }
};