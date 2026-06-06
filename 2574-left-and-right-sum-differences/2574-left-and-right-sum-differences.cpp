class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        int total_sum = 0;
        for (int& num : nums) {
            total_sum += num;
        }
        vector<int> ans;
        int left_sum = 0;
        for (int& num : nums) {
            left_sum += num;
            int right_sum = total_sum - left_sum;
            left_sum -= num;
            ans.push_back(abs(left_sum - right_sum));
            left_sum += num;
        }
        return ans;
    }
};