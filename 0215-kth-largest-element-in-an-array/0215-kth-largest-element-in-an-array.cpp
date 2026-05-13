class Solution {
public:
    int randomIndex(int& left, int& right) {
        int len = right - left + 1;
        return (rand() % len) + left;
    }
    int partitionAndReturnIndex(vector<int>& nums, int pivotIndex, int left, int right) {
        int pivot = nums[pivotIndex];

        swap(nums[left], nums[pivotIndex]);

        int ind = left + 1;

        for (int i = left + 1; i <= right; i++) {
            if (nums[i] > pivot) {
                swap(nums[ind], nums[i]);
                ind++;
            }
        }

        swap(nums[left], nums[ind - 1]);

        return ind - 1;
    }
    int findKthLargest(vector<int>& nums, int k) {
        if (k > nums.size())
            return -1;

        int left = 0, right = nums.size() - 1;

        while (true) {
            int pivotIndex = randomIndex(left, right);
            pivotIndex = partitionAndReturnIndex(nums, pivotIndex, left, right);

            if (pivotIndex == k - 1)
                return nums[pivotIndex];
            else if (pivotIndex > k - 1)
                right = pivotIndex - 1;
            else
                left = pivotIndex + 1;
        }
        return -1;
    }
};
