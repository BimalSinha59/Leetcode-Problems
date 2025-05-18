class Solution {
public:
    int f(int ind,int tsn,vector<int>& prices,int n,vector<vector<int>> &dp){
        if(ind==n || tsn==4){
            return 0;
        }
        if(dp[ind][tsn]!=-1){
            return dp[ind][tsn];
        }
        if(tsn%2==0){
            return dp[ind][tsn]=max(-prices[ind]+f(ind+1,tsn+1,prices,n,dp),0+f(ind+1,tsn,prices,n,dp));
        }
        else{
            return dp[ind][tsn]=max(prices[ind]+f(ind+1,tsn+1,prices,n,dp),0+f(ind+1,tsn,prices,n,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<int>>dp(n,vector<int>(4,-1));
        // return f(0,0,prices,n,dp);

        vector<vector<int>>dp(n+1,vector<int>(5,0));
        for(int ind=n-1; ind>=0; ind--){
            for(int tsn=0; tsn<4; tsn++){
                if(tsn%2==0){
                    dp[ind][tsn]=max(-prices[ind]+dp[ind+1][tsn+1],0+dp[ind+1][tsn]);
                }
                else{
                    dp[ind][tsn]=max(prices[ind]+dp[ind+1][tsn+1],0+dp[ind+1][tsn]);
                }
            }
        }
        return dp[0][0];
    }
};