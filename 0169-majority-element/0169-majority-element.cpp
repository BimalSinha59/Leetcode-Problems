class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int freq_count = 0;
        int majElement = -1;
        for (int i = 0; i < n; i++) {
            if (freq_count == 0) {
                freq_count = 1;
                majElement = nums[i];
            } else if (nums[i] == majElement) {
                freq_count++;
            } else {
                freq_count--;
            }
        }
        return majElement;
    }
};