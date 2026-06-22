class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            long long sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                int last_dig = sum % 10;
                long long nsum = sum;
                int first_dig = 0;
                while (nsum > 0) {
                    first_dig = nsum;
                    nsum /= 10;
                }
                if (first_dig == x && last_dig == x) {
                    ans++;
                }
            }
        }
        return ans;
    }
};