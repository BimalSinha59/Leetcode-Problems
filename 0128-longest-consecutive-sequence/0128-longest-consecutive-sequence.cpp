class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 0;
        for (int num : st) {
            if (st.count(num - 1) == 0) {
                int curr_num = num + 1;
                int count = 1;
                while (st.count(curr_num)) {
                    count++;
                    curr_num++;
                }
                longest = max(longest, count);
            }
        }
        return longest;
    }
};