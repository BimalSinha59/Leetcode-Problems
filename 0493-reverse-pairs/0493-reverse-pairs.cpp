class Solution {
public:
    void merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;
        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            } 
            else {
                temp.push_back(nums[right]);
                right++;
            }
        }
        while (left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }
        while (right <= high) {
            temp.push_back(nums[right]);
            right++;
        }
        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }
    int countRevPairs(vector<int>& nums, int low, int mid, int high) {
        int left = low;
        int right = mid + 1;
        int count = 0;
        while (left <= mid) {
            while (right <= high && nums[left] > 2 *1LL* nums[right]) {
                right++;
            }
            count += (right - (mid + 1));
            left++;
        }
        return count;
    }
    void mergeSort(vector<int>& nums, int low, int high, int& ans) {
        if (low >= high) {
            return;
        }
        int mid = (low + high) / 2;
        mergeSort(nums, low, mid, ans);
        mergeSort(nums, mid + 1, high, ans);
        ans += countRevPairs(nums, low, mid, high);
        merge(nums, low, mid, high);
    }
    int reversePairs(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        mergeSort(nums, 0, n - 1, ans);
        return ans;
    }
};