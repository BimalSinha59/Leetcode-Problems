class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int num1 = 0, olgcd = 0;

        for (int x : nums) {
            if (x == 1) num1++;
            olgcd = gcd(olgcd, x);
        }

        if (num1 > 0) return n - num1;
        if (olgcd > 1) return -1;

        int mnln = n;
        for (int i = 0; i < n; i++) {
            int g = nums[i];
            if (g == 1) {
                mnln = 1;
                break; 
            }
            for (int j = i + 1; j < n; j++) {
                g = gcd(g, nums[j]);
                if (g == 1) {
                    mnln = min(mnln, j - i + 1);
                    break;
                }
            }
        }

        return mnln + n - 2;
    }
};