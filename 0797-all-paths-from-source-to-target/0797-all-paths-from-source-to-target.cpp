class Solution {
public:
    void dfs(int src,int tar,vector<vector<int>>& graph,vector<vector<int>>& ans,vector<int>& v){
        if(src==tar){
            v.push_back(tar);
            ans.push_back(v);
            v.pop_back();
            return;
        }
        v.push_back(src);
        for(auto it:graph[src]){
            dfs(it,tar,graph,ans,v);
        }
        v.pop_back();
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
          vector<vector<int>>ans;
          vector<int>v;
          int n=graph.size();
          dfs(0,n-1,graph,ans,v);
          return ans;
    }
};