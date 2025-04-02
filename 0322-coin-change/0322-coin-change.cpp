class Solution {
public:
    int f(int idx,int val,vector<int>& coins,vector<vector<int>>& dp){
        if(idx==0){
            if(val%coins[0]==0){
                return val/coins[0];
            }
            else{
                return 1e9;
            }
        }
        if(dp[idx][val]!=-1){
            return dp[idx][val];
        }
        int ntake=0+f(idx-1,val,coins,dp);
        int take=1e9;
        if(val>=coins[idx]){
            take=1+f(idx,val-coins[idx],coins,dp);
        }
        return dp[idx][val]=min(take,ntake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans= f(n-1,amount,coins,dp);
        if(ans==1e9){
            return -1;
        }
        return ans;
        
    }
};