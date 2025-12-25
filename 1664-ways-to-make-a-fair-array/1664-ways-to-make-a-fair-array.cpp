class Solution {
public:
    bool allSame(vector<int>& nums, int n) {
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] != nums[i]) {
                return false;
            }
        }
        return true;
    }
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        int os = 0, es = 0;
        if (allSame(nums, n) && (n & 1)) {
            return n;
        }
        vector<int> pso(n, 0), pse(n, 0);
        for (int i = 0; i < n; i++) {
            if (i - 1 >= 0) {
                pso[i] = pso[i - 1];
                pse[i] = pse[i - 1];
            }
            if (i & 1) {
                os += nums[i];
                pso[i] += nums[i];
            } else {
                es += nums[i];
                pse[i] += nums[i];
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int s1, s2;
            int a = 0, b = 0, c = 0;
            if (i & 1) {
                if (i - 1 >= 0) {
                    a = pse[i - 1];
                }
                if (i + 1 < n) {
                    b = pso[i + 1];
                }
                if (i - 2 >= 0) {
                    c = pso[i - 2];
                }
                s1 = a + os - b;
                s2 = c + es - a;
                if (s1 == s2) {
                    ans++;
                }
            } else {
                if (i - 1 >= 0) {
                    a = pso[i - 1];
                }
                if (i + 1 < n) {
                    b = pse[i + 1];
                }
                if (i - 2 >= 0) {
                    c = pse[i - 2];
                }
                s1 = a + es - b;
                s2 = c + os - a;
                if (s1 == s2) {
                    ans++;
                }
            }
        }
        return ans;
    }
};