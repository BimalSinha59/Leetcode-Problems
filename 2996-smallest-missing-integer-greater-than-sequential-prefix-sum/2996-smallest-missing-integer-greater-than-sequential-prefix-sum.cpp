class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        int i;
        for (i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else {
                break;
            }
        }
        unordered_set<int> st;
        if (sum == nums[0]) {
            st.insert(sum);
        }
        while (i < n) {
            st.insert(nums[i]);
            i++;
        }
        for (int j = sum;; j++) {
            if (st.count(j) == 0) {
                return j;
            }
        }
        return 0;
    }
};