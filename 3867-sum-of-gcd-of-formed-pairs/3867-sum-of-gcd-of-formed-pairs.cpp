class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
        vector<int> prefixGcd;
        for (int& num : nums) {
            mx = max(mx, num);
            int gcdValue = __gcd(num, mx);
            prefixGcd.push_back(gcdValue);
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        long long sum = 0;
        for (int i = 0; i < n / 2; i++) {
            int gcdValue = __gcd(prefixGcd[i], prefixGcd[n - i - 1]);
            sum += gcdValue;
        }
        return sum;
    }
};