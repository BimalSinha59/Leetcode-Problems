class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int idx = 0;
        int i = 1;
        int k = 1;
        while (i < n) {
            while (i < n && nums[i] == nums[idx]) {
                i++;
            }
            idx++;
            if (i < n) {
                nums[idx] = nums[i];
                k++;
            }
            i++;
        }
        return k;
    }
};