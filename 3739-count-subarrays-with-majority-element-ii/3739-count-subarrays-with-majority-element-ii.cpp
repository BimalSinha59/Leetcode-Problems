class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int cummSum = 0;
        long long totalValidPairs = 0;
        long long noOfMajEle = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                totalValidPairs += mp[cummSum];
                cummSum++;
            } else {
                cummSum--;
                totalValidPairs -= mp[cummSum];
            }
            noOfMajEle += totalValidPairs;
            mp[cummSum]++;
        }
        return noOfMajEle;
    }
};