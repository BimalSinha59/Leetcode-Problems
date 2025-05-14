class Solution {
public:
    // int f(int i,int j, string &s1,string &s2,vector<vector<int>>& dp){
    //     if(i<0 || j<0){
    //         return 0;
    //     }
    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }
    //     if(s1[i]==s2[j]){
    //         return dp[i][j]=1+f(i-1,j-1,s1,s2,dp);
    //     }
    //     return dp[i][j]=max(f(i,j-1,s1,s2,dp),f(i-1,j,s1,s2,dp));
    // }
    int longestPalindromeSubseq(string s) {
        string s1=s;
        reverse(s.begin(),s.end());
        string s2=s;
        int n=s.size();
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        //return f(n-1,n-1,s1,s2,dp);
        
         vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int j=0; j<=n; j++){
            dp[0][j]=0;
        }
        for(int i=0; i<=n; i++){
            dp[i][0]=0;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[n][n];
    }
};