class Solution {
public:
    int solve(int idx,vector<int>& nums,vector<int>& dp){
        if(idx==0){
            return nums[0];
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int take=nums[idx];
        if(idx>1){
            take+=solve(idx-2,nums,dp);
        }
        int dtake=0+solve(idx-1,nums,dp);
        return dp[idx]=max(take,dtake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(n-1,nums,dp);

        // int prev=nums[0];
        // int prev2=0;
        // for(int i=1; i<n; i++){
        //     int take=nums[i];
        //     if(i>1){
        //         take+=prev2;
        //     }
        //     int dtake=0+prev;
        //     int curr=max(take,dtake);
        //     prev2=prev;
        //     prev=curr;
        // }
        // return prev;
        
    }
};