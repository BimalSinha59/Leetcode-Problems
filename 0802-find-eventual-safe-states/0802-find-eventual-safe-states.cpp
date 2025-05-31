class Solution {
public:
    bool dfsCheck(int node,vector<vector<int>>& graph,vector<int>& vis,vector<int>& pvis){
        vis[node]=1;
        pvis[node]=1;
        for(auto it:graph[node]){
            if(vis[it]==0){
                if(dfsCheck(it,graph,vis,pvis)){
                    return true;
                }
            }
            else if(vis[it]==pvis[it]){
                return true;
            }
        }
        pvis[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,0),pvis(n,0);
        for(int i=0; i<n; i++){
            if(vis[i]==0){
                dfsCheck(i,graph,vis,pvis);
            }
        }
        vector<int>ans;
        for(int i=0; i<n; i++){
            if(pvis[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};