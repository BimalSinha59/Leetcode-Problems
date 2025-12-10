class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        int mini = INT_MAX;
        for (int i = 1; i < n; i++) {
            mini = min(mini, complexity[i]);
        }
        if (mini <= complexity[0]) {
            return 0;
        }
        int mod = 1e9 + 7;
        int ans = 1;
        for (int i = 1; i < n; i++) {
            ans = (1LL * ans * i) % mod;
        }
        return ans;
    }
};