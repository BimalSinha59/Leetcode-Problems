class Solution {
public:
    int findGCD(int a, int b) {
        if (a == 0) {
            return b;
        }
        if (b == 0) {
            return a;
        }
        if (a > b) {
            return findGCD(a % b, b);
        }
        return findGCD(a, b % a);
    }
    int findGCD(vector<int>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for (int& num : nums) {
            mini = min(mini, num);
            maxi = max(maxi, num);
        }
        int ans = findGCD(mini, maxi);
        return ans;
    }
};