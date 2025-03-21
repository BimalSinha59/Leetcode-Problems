class Solution {
public:
    bool f(vector<int>& nums,int idx,int n,vector<pair<int,bool>>& dp){
        if(idx==n-1){
            return true;
        }
        if(idx>=n){
            return false;
        }
        if(dp[idx].first!=-1){
            return dp[idx].second;
        }
        int x=nums[idx];
        bool temp=false;
        for(int i=1; i<=x; i++){
            // dp[idx+i].first=idx+i;
            temp=temp || f(nums,idx+i,n,dp);
        }
        dp[idx].first=idx;
        return dp[idx].second=temp;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,bool>>dp;
        for(int i=0; i<n; i++){
            dp.push_back({-1,false});
        }
        return f(nums,0,n,dp);
        
    }
};