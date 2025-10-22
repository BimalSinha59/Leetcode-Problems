class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        unordered_map<int, int> mp, freq;
        set<int> st;
        for (int num : nums) {
            freq[num]++;
            mp[num - k]++;
            mp[num + k + 1]--;
            st.insert(num);
            st.insert(num - k);
            st.insert(num + k + 1);
        }
        int ans = 1;
        int sum = 0;
        for (int ele : st) {
            sum += mp[ele];
            int ext = min(sum - freq[ele], numOperations);
            ans = max(ans, freq[ele] + ext);
        }
        return ans;
    }
};