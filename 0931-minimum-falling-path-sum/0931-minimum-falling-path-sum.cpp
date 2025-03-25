class Solution {
public:
    int f(int i,int j,int n,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        if(j<0 || j>=n){
            return 1e8;
        }
        if(i==0){
            return matrix[0][j];
        }
        if(dp[i][j]!=-1e8){
            return dp[i][j];
        }
        int st=matrix[i][j]+f(i-1,j,n,matrix,dp);
        int ld=matrix[i][j]+f(i-1,j-1,n,matrix,dp);
        int rd=matrix[i][j]+f(i-1,j+1,n,matrix,dp);
        return dp[i][j]=min(st,min(ld,rd));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int mini=1e8;
        vector<vector<int>>dp(n,vector<int>(n,-1e8));
        for(int i=0; i<n; i++){
            mini=min(mini,f(n-1,i,n,matrix,dp));
        }
        return mini;
        
    }
};