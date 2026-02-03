class Solution {
public:
    int lis(vector<int>& arr) {
        int n = arr.size();
        vector<int> temp;
        int len = 1;
        temp.push_back(arr[0]);
        for (int i = 1; i < n; i++) {
            if (arr[i] > temp.back()) {
                temp.push_back(arr[i]);
                len++;
            } else {
                int low = 0, high = temp.size() - 1;
                int idx;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (temp[mid] < arr[i]) {
                        low = mid + 1;
                    } else {
                        idx = mid;
                        high = mid - 1;
                    }
                }
                temp[idx] = arr[i];
            }
        }
        return len;
    }
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int bit = 0; bit < 31; bit++) {
            vector<int> arr;
            for (int i = 0; i < n; i++) {
                if ((nums[i] & (1 << bit))) {
                    arr.push_back(nums[i]);
                }
            }
            int len = 0;
            if (arr.size() > ans) {
                len = lis(arr);
            }
            ans = max(ans, len);
        }
        return ans;
    }
};