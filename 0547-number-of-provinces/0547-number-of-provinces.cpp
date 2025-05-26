class Solution {
public:
    void bfs(int idx,vector<vector<int>>& adjL,vector<int>& vis){
        vis[idx]=1;
        queue<int>q;
        q.push(idx);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adjL[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int m=isConnected[0].size();
        vector<vector<int>>adjL(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                 if(isConnected[i][j]==1 && i!=j){
                    adjL[i].push_back(j);
                 }
            }
        }
        int ans=0;
        vector<int>vis(n,0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                ans++;
                bfs(i,adjL,vis);
            }
        }
        
        return ans;
    }
};