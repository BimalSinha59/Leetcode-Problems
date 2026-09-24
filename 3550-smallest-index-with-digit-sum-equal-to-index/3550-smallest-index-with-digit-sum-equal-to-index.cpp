class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int sum = 0;
            while (num > 0) {
                int dig = num % 10;
                sum += dig;
                num /= 10;
            }
            if (sum == i) {
                return i;
            }
        }
        return -1;
    }
};