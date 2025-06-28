class Solution {
public:
    bool checkBP(vector<int> adj[], int start, vector<int>& color){
        color[start]=0;
        queue<int>q;
        q.push(start);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
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
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> adj[n+1];
        for(auto it:dislikes){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>color(n+1,-1);   
        for(int i=1; i<=n; i++){
            if(color[i]==-1){
                if(!checkBP(adj, i, color)){
                    return false;
                }
            }
        }  
        return true;   
    }
};