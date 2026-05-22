class Solution {
public:
    int findPivotIndex(vector<int>& nums, int left, int right) {
        int n = nums.size();
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid + 1 < n && nums[mid] > nums[mid + 1]) {
                return mid;
            }
            if (mid - 1 >= 0 && nums[mid - 1] > nums[mid]) {
                return mid - 1;
            }
            if (nums[left] > nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return n - 1;
    }
    int BinarySearch(vector<int>& nums, int left, int right, int target) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        int pivotIndex = findPivotIndex(nums, left, right);
        if (target >= nums[left] && target <= nums[pivotIndex]) {
            return BinarySearch(nums, left, pivotIndex, target);
        } else if (pivotIndex + 1 < n && target >= nums[pivotIndex + 1] &&
                   target <= nums[right]) {
            return BinarySearch(nums, pivotIndex + 1, right, target);
        }
        return -1;
    }
};