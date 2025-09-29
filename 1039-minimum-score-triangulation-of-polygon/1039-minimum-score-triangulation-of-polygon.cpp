class Solution {
public:
    int f(int i, int j, vector<int>& values, vector<vector<int>>& dp){
        if(i+2>j){
            return 0;
        }
        if(i+2==j){
            return values[i]*values[i+1]*values[j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=1e9;
        for(int k=i+1; k<j; k++){
            ans=min(ans,values[i]*values[k]*values[j]+f(i,k,values,dp)+f(k,j,values,dp));
        }
        return dp[i][j]=ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return f(0,n-1,values,dp);
    }
};