class Solution {
public:
    int f(int i,vector<int>& v, int tar,vector<vector<int>>& dp){
        if(i==0){
            return tar;
        }
        if(dp[i][tar]!=-1){
            return dp[i][tar];
        }
        int ntake=0+f(i-1,v,tar,dp);
        int take = 1e9;
        if(tar>=v[i]){
           take=1+f(i,v,tar-v[i],dp);
        }
        return dp[i][tar]=min(take,ntake);
    }
    int numSquares(int n) {
        if(n==1){
            return 1;
        }
        vector<int>v;
        for(int i=1; i<=n/2; i++){
            if(i*i<=n){
                v.push_back(i*i);
            }
        }
        int m=v.size();
        //return f(m-1,v,n,dp);

        //vector<vector<int>>dp(m,vector<int>(n+1,0));
        vector<int>prev(n+1,0),curr(n+1,0);
        for(int i=0; i<=n; i++){
            prev[i]=i;
        }
        for(int i=1; i<m; i++){
            for(int j=0; j<=n; j++){
                int ntake=0+prev[j];
                int take=1e9;
                if(j>=v[i]){
                    take=1+curr[j-v[i]];
                }
                curr[j]=min(take,ntake);
            }
            prev=curr;
        }
        return prev[n];
    }
};