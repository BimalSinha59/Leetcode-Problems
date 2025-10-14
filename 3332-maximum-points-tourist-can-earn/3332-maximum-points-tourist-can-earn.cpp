class Solution {
public:
    int f(int d, int city,vector<vector<int>>& stayScore, vector<vector<int>>& travelScore, int n, int k,vector<vector<int>>& dp){
        if(d==k-1){
            int ans=stayScore[d][city];
            for(int i=0; i<n; i++){
                if(i!=city){
                    ans=max(ans,travelScore[city][i]);
                }
            }
            return ans;
        }
        if(dp[d][city]!=-1){
            return dp[d][city];
        }
        int ans1=stayScore[d][city]+f(d+1,city,stayScore,travelScore,n,k,dp);
        int ans2=-1e9;
        for(int i=0; i<n; i++){
            if(i!=city){
                ans2=max(ans2,travelScore[city][i]+f(d+1,i,stayScore,travelScore,n,k,dp));
            }
        }
        return dp[d][city] = max(ans1,ans2);
    }
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        int ans=0;
        vector<vector<int>>dp(k,vector<int>(n,-1));
        for(int i=0; i<n; i++){
            ans=max(ans,f(0,i,stayScore,travelScore,n,k,dp));
        }
        return ans;
    }
};