class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        long long lsum = 0, rsum = 0;
        while (i + 1 < n && nums[i + 1] > nums[i]) {
            lsum += nums[i];
            i++;
        }
        int j = n - 1;
        while (j - 1 >= 0 && nums[j - 1] > nums[j]) {
            rsum += nums[j];
            j--;
        }
        if (i != j) {
            if (j == i + 1) {
                return max(lsum, rsum);
            }
            return -1;
        }
        return min(abs((lsum + nums[i]) - rsum), abs(lsum - (rsum + nums[i])));
    }
};