class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int s = 0, e = n - 1;
        int idx = -1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (mid + 1 < n && nums[mid + 1] < nums[mid]) {
                return nums[mid + 1];
            } else if (mid - 1 >= 0 && nums[mid] < nums[mid - 1]) {
                return nums[mid];
            } else if (nums[s] > nums[mid]) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return nums[0];
    }
};