class Solution {
public:
    bool bfsCheck(int start,vector<vector<int>>& graph,vector<int>& color){
        queue<int>q;
        q.push(start);
        color[start]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:graph[node]){
                if(color[it]==-1){
                    color[it]=!color[node];
                    q.push(it);
                }
                else if(color[it]==color[node]){
                    return false;
                }
            }
        }
        return true;
    }
    bool dfsCheck(int start,vector<vector<int>>& graph,vector<int>& color,int col){
        color[start]=col;
        for(auto it:graph[start]){
            if(color[it]==-1){
                if(dfsCheck(it,graph,color,!col)==false){
                    return false;
                }
            }
            else if(color[it]==col){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0; i<n; i++){
            if(color[i]==-1){
                if(dfsCheck(i,graph,color,0)==false){
                    return false;
                }
            }
        }
        return true;
    }
};