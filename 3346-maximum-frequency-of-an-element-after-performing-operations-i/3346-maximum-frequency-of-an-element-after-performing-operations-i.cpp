class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end()) + k + 2;
        vector<int> pmp(maxi, 0);
        for (auto it : nums) {
            pmp[it]++;
        }
        for (int i = 1; i < maxi; i++) {
            pmp[i] += pmp[i - 1];
        }
        int ans = 0;
        for (int i = 0; i < maxi; i++) {
            int lt = max(0, i - k);
            int rt = min(maxi - 1, i + k);
            int total = pmp[rt];
            if (lt - 1 >= 0) {
                total -= pmp[lt - 1];
            }
            int freq = pmp[i];
            if (i - 1 >= 0) {
                freq -= pmp[i - 1];
            }
            ans = max(ans, freq + min(numOperations, total - freq));
        }
        return ans;
    }
};