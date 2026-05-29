class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = 1e9;
        for (int& num : nums) {
            int sum = 0;
            while (num > 0) {
                int dig = num % 10;
                sum += dig;
                num /= 10;
            }
            ans = min(ans, sum);
        }
        return ans;
    }
};