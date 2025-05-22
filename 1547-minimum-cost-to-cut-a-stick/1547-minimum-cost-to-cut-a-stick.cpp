class Solution {
public:
    int f(int i,int j,vector<int>& cuts,vector<vector<int>>& dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int minCost=1e9;
        for(int ind=i; ind<=j; ind++){
            int cost=cuts[j+1]-cuts[i-1]+f(i,ind-1,cuts,dp)+f(ind+1,j,cuts,dp);
            minCost=min(minCost,cost);
        }
        return dp[i][j]=minCost;
    }
    int minCost(int n, vector<int>& cuts) {
        int m=cuts.size();
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        vector<vector<int>>dp(m+1,vector<int>(m+1,-1));
        return f(1,m,cuts,dp);
        
    }
};