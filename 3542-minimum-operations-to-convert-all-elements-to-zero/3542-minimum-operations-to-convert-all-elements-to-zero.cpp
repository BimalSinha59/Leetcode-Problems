class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> st(n + 1, 0);
        int tp = 0, ans = 0;
        for (int& num : nums) {
            while (st[tp] > num) {
                tp--;
                ans++;
            }
            if (st[tp] != num) {
                tp++;
                st[tp] = num;
            }
        }
        return ans + tp;
    }
};