class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(int i=0; i<flights.size(); i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int w=flights[i][2];
            adj[u].push_back({v,w});
        }
        queue<pair<int,pair<int,int>>>q;
        vector<int>dist(n,1e9);
        q.push({0,{src,0}});
        dist[src]=0;
        while(!q.empty()){
            int stops=q.front().first;
            int node=q.front().second.first;
            int cost=q.front().second.second;
            q.pop();
            if(stops>k){
                continue;
            }
            for(auto it:adj[node]){
                int adjNode=it.first;
                int edW=it.second;
                if(edW+cost<dist[adjNode] && stops<=k){
                    dist[adjNode]=edW+cost;
                    q.push({stops+1,{adjNode,edW+cost}});
                }
            }

        }
        if(dist[dst]==1e9){
            return -1;
        }
        return dist[dst];
    }
};