class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int p = -1, q = -1;
        int i = 0, j = 1;
        while (j < n && nums[j] > nums[i]) {
            i++;
            j++;
        }
        p = i;
        while (j < n && nums[j] < nums[i]) {
            i++;
            j++;
        }
        q = i;
        bool flg = true;
        for (int k = j; k < n; k++) {
            if (nums[k] <= nums[k - 1]) {
                flg = false;
                break;
            }
        }
        if (p < q && (p > 0 && p < n - 2 && q > 1 && q < n - 1) && flg) {
            return true;
        }
        return false;
    }
};