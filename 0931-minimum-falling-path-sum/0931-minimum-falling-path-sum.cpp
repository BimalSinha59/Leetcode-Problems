class Solution {
public:
    /////Memoization/////////
    // int f(int i,int j,int n,vector<vector<int>>& matrix,vector<vector<int>>& dp){
    //     if(j<0 || j>=n){
    //         return 1e8;
    //     }
    //     if(i==0){
    //         return matrix[0][j];
    //     }
    //     if(dp[i][j]!=-1e8){
    //         return dp[i][j];
    //     }
    //     int st=matrix[i][j]+f(i-1,j,n,matrix,dp);
    //     int ld=matrix[i][j]+f(i-1,j-1,n,matrix,dp);
    //     int rd=matrix[i][j]+f(i-1,j+1,n,matrix,dp);
    //     return dp[i][j]=min(st,min(ld,rd));
    // }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        //int mini=1e8;
        //vector<vector<int>>dp(n,vector<int>(n,-1e8));
        // for(int i=0; i<n; i++){
        //     mini=min(mini,f(n-1,i,n,matrix,dp));
        // }
        // return mini;

        //////////Tabulation////////

        // for(int i=0; i<n; i++){
        //     dp[0][i]=matrix[0][i];
        // }

        // for(int i=1; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         int st=matrix[i][j]+dp[i-1][j];
        //         int ld=matrix[i][j];
        //         if(j-1>=0){
        //             ld+=dp[i-1][j-1];
        //         }
        //         else{
        //             ld=1e8;
        //         }
        //         int rd=matrix[i][j];
        //         if(j+1<n){
        //             rd+=dp[i-1][j+1];
        //         }
        //         else{
        //             rd=1e8;
        //         }
        //         dp[i][j]=min(st,min(ld,rd));
        //     }
        // }

        // for(int i=0; i<n; i++){
        //     mini=min(mini,dp[n-1][i]);
        // }
        // return mini;


        ///////Space Optimization//////////
        vector<int>prev(n),curr(n);
        for(int i=0; i<n; i++){
            prev[i]=matrix[0][i];
        }

        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                int st=matrix[i][j]+prev[j];
                int ld=matrix[i][j];
                if(j-1>=0){
                    ld+=prev[j-1];
                }
                else{
                    ld=1e8;
                }
                int rd=matrix[i][j];
                if(j+1<n){
                    rd+=prev[j+1];
                }
                else{
                    rd=1e8;
                }
                curr[j]=min(st,min(ld,rd));
            }
            prev=curr;
        }
        int mini=1e8;
        for(int i=0; i<n; i++){
            mini=min(mini,prev[i]);
        }
        return mini;


        
    }
};