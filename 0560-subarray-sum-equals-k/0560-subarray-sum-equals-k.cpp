class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int countSubArrays = 0;
        unordered_map<int, int> prefSumFreq;
        int prefSum = 0;
        prefSumFreq[0] = 1;
        for (int& num : nums) {
            prefSum += num;
            int needToRemove = prefSum - k;
            if (prefSumFreq.count(needToRemove)) {
                countSubArrays += prefSumFreq[needToRemove];
            }
            prefSumFreq[prefSum]++;
        }
        return countSubArrays;
    }
};