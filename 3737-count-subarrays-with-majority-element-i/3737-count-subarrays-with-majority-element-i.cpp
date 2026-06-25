class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> pcnt(n, 0);
        pcnt[0] = nums[0] == target;
        for (int i = 1; i < n; i++) {
            pcnt[i] = nums[i] == target ? pcnt[i - 1] + 1 : pcnt[i - 1];
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int freq = pcnt[j] - (i - 1 >= 0 ? pcnt[i - 1] : 0);
                int len = j - i + 1;
                if (freq > len / 2) {
                    ans++;
                }
            }
        }
        return ans;
    }
};