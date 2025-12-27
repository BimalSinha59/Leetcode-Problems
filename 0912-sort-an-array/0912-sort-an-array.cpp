class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int offset = 50000;                 
        int range = 100001;

        vector<int> count(range, 0);
        for (int x : nums) {
            count[x + offset]++;
        }
        int idx = 0;
        for (int i = 0; i < range; i++) {
            while (count[i]--) {
                nums[idx++] = i - offset;
            }
        }

        return nums;
    }
};