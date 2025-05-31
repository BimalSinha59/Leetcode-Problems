class Solution {
public:
    bool dfsCheck(int node,vector<vector<int>>& graph,vector<int>& vis){
        vis[node]=1;
        for(auto it:graph[node]){
            if(vis[it]==0){
                if(dfsCheck(it,graph,vis)){
                    return true;
                }
            }
            else if(vis[it]==1){
                return true;
            }
        }
        vis[node]=2;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,0);
        for(int i=0; i<n; i++){
            if(vis[i]==0){
                dfsCheck(i,graph,vis);
            }
        }
        vector<int>ans;
        for(int i=0; i<n; i++){
            if(vis[i]==2){
                ans.push_back(i);
            }
        }
        return ans;
    }
};