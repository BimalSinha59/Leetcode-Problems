class Solution {
public:
    int calculateGCD(int a, int b) {
        while (true) {
            if (a == 0) {
                return b;
            }
            if (b == 0) {
                return a;
            }
            if (a > b) {
                a = a % b;
            } else {
                b = b % a;
            }
        }
        return 0;
    }
    int findGCD(vector<int>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for (int& num : nums) {
            mini = min(mini, num);
            maxi = max(maxi, num);
        }
        int ans = calculateGCD(mini, maxi);
        return ans;
    }
};