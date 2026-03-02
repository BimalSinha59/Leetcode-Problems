class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int n = nums.size();
        int poscr = 0, psscr = 0;
        bool flg = true;
        for (int i = 0; i < n; i++) {
            if (((nums[i] & 1) || (i + 1) % 6 == 0) &&
                !((nums[i] & 1) && (i + 1) % 6 == 0)) {
                flg = !flg;
            }
            if (flg) {
                poscr += nums[i];
            } else {
                psscr += nums[i];
            }
        }
        return poscr - psscr;
    }
};