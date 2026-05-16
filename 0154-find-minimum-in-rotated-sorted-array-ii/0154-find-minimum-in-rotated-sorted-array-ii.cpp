class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size() - 1;
        int lst = nums[n];
        int s = 0, e = n;
        while (s < n && nums[s] == lst) {
            s++;
        }
        while (s < e) {
            int mid = (s + e) >> 1;
            if (nums[mid] > lst) {
                s = mid + 1;
            } else {
                e = mid;
            }
        }
        return nums[s];
    }
};