class Solution {
public:
    bool isPalindrome(int i,int j,string &s){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int f(int i,string &s,int n,vector<int> &dp){
        if(i==n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int minCuts=1e9;
        for(int j=i; j<n; j++){
            if(isPalindrome(i,j,s)){
                int cuts=1+f(j+1,s,n,dp);
                minCuts=min(minCuts,cuts);
            }
        }
        return dp[i]=minCuts;
    }
    int minCut(string s) {
        int n=s.size();
        // vector<int>dp(n,-1);
        // return f(0,s,n,dp)-1;
        vector<int>dp(n+1,0);
        for(int i=n-1; i>=0; i--){
            int minCuts=1e9;
            for(int j=i; j<n; j++){
                if(isPalindrome(i,j,s)){
                    int cuts=1+dp[j+1];
                    minCuts=min(minCuts,cuts);
                }
            }
            dp[i]=minCuts;
        }
        return dp[0]-1;
    }
};