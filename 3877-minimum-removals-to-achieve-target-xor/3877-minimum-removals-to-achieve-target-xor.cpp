class Solution {
public:
    vector<unordered_map<int, int>> dp;
    int solve(int i, int tgt, vector<int>& nums) {
        if (i < 0) {
            if (tgt == 0) {
                return 0;
            }
            return -1;
        }
        if(dp[i].count(tgt)){
            return dp[i][tgt];
        }
        int take=-1;
        take=solve(i-1,tgt^nums[i],nums);
        if(take!=-1){
            take++;
        }
        int notTake=solve(i-1,tgt,nums);
        return dp[i][tgt]=max(take, notTake);
    }
    int minRemovals(vector<int>& nums, int target) {
        int n = nums.size();
        dp = vector<unordered_map<int, int>>(n, unordered_map<int, int>());
        int ans = solve(n - 1, target, nums);
        return ans == -1 ? -1 : n - ans;
    }
};