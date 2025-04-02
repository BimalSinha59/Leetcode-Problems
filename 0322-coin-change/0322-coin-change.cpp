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
        // int ans= f(n-1,amount,coins,dp);
        // if(ans==1e9){
        //     return -1;
        // }
        // return ans;

        for(int val=0; val<=amount; val++){
            if(val%coins[0]==0){
                dp[0][val]=val/coins[0];
            }
            else{
                dp[0][val]=1e9;
            }
        }
        for(int idx=1; idx<n; idx++){
            for(int val=0; val<=amount; val++){
                int ntake=0+dp[idx-1][val];
                int take=1e9;
                if(val>=coins[idx]){
                    take=1+dp[idx][val-coins[idx]];
                }
                dp[idx][val]=min(take,ntake);
            }
        }
        if(dp[n-1][amount]==1e9){
            return -1;
        }
        return dp[n-1][amount];
        
    }
};