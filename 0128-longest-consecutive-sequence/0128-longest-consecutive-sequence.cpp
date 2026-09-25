class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 0;
        while (!st.empty()) {
            int num = *st.begin();
            int small_count = 0;
            int large_count = 0;
            int small_num = num - 1;
            int large_num = num + 1;
            while (st.count(small_num)) {
                small_count++;
                st.erase(small_num);
                small_num--;
            }
            while (st.count(large_num)) {
                large_count++;
                st.erase(large_num);
                large_num++;
            }
            st.erase(num);
            int total_count = small_count + large_count + 1;
            longest = max(longest, total_count);
        }
        return longest;
    }
};