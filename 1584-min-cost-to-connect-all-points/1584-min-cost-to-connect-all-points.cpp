class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<pair<int,int>>>adj;
        for(int i=0; i<n; i++){
            vector<pair<int,int>>v;
            for(int j=0; j<n; j++){
                if(i==j){
                    continue;
                }
                int dis=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                v.push_back({j,dis});
            }
            adj.push_back(v);
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        int sum=0;
        vector<int>vis(n,0);
        while(!pq.empty()){
            int node=pq.top().second;
            int wt=pq.top().first;
            pq.pop();
            if(vis[node]==1){
                continue;
            }
            vis[node]=1;
            sum+=wt;
            for(auto it:adj[node]){
                int adjNode=it.first;
                int ewt=it.second;
                if(!vis[adjNode]){
                    pq.push({ewt,adjNode});
                }
            }
        }
        return sum;
        
    }
};