class Solution {
public:
    int f(int ind,int tar,vector<int>& nums,vector<vector<int>>& dp){

        if(ind==0){
            if(tar==0 && nums[0]==0){
                return 2;
            }
            if(tar==0 || tar==nums[0]){
                return 1;
            }
            return 0;
        }
        if(dp[ind][tar]!=-1){
            return dp[ind][tar];
        }
        int ntake=f(ind-1,tar,nums,dp);
        int take=0;
        if(tar>=nums[ind]){
            take=f(ind-1,tar-nums[ind],nums,dp);
        }
        return dp[ind][tar]=take+ntake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        int n=nums.size();
        for(int i=0; i<n; i++){
            sum+=nums[i];
        }
        int diff=sum-target;
        if(diff%2!=0 || diff<0){
            return 0;
        }
        int k=diff/2;
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return f(n-1,k,nums,dp);

        
    }
};