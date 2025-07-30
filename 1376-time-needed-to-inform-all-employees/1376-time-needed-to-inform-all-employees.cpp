class Solution {
public:
    void dfs(int node,int para,vector<int> adj[], vector<int>& informTime, int &ans, int &maxi){
        ans+=informTime[node];
        for(auto child:adj[node]){
            if(child==para){
                continue;
            }
            if(informTime[child]==0){
                maxi=max(maxi,ans);
            }
            dfs(child,node,adj,informTime,ans,maxi);
        }
        ans-=informTime[node];
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[n];
        for(int i=0; i<n; i++){
            if(manager[i]!=-1){
                adj[i].push_back(manager[i]);
                adj[manager[i]].push_back(i);
            }
        }
        int maxi=0;
        int ans=0;
        dfs(headID,-1,adj,informTime,ans,maxi);
        return maxi;
    }
};