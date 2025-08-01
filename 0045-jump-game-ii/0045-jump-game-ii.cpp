class Solution {
public:
    int f(int i,vector<int>& nums, int n,vector<int>& dp){
        if(i>=n){
            return 1e9;
        }
        if(i==n-1){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        if(nums[i]==0){
            return dp[i]=1e9;
        }
        int ans=1e9;
        for(int j=1; j<=nums[i]; j++){
            int x=1+f(i+j,nums,n,dp);
            ans=min(ans,x);
        }
        return dp[i]=ans;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return f(0,nums,n,dp);
    }
};