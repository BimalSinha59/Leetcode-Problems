class Solution {
public:
    int f(int i,vector<int>& arr,int n,int k,vector<int> &dp){
        if(i==n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int maxSum=-1e9;
        int len=0;
        int maxE=-1e9;
        for(int j=i; j<min(i+k,n); j++){
            maxE=max(maxE,arr[j]);
            len++;
            int sum=(maxE*len)+f(j+1,arr,n,k,dp);
            maxSum=max(maxSum,sum);
        }
        return dp[i]=maxSum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n,-1);
        return f(0,arr,n,k,dp);   
    }
};