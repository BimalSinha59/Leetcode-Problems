class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0; i<times.size(); i++){
            int u=times[i][0];
            int v=times[i][1];
            int w=times[i][2];
            adj[u].push_back({v,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>time(n+1,1e9);
        pq.push({0,k});
        time[k]=0;
        while(!pq.empty()){
            int adjTime=pq.top().first;
            int adjNode=pq.top().second;
            pq.pop();
            for(auto it:adj[adjNode]){
                int v=it.first;
                int w=it.second;
                if(adjTime+w<time[v]){
                    time[v]=adjTime+w;
                    pq.push({time[v],v});
                }
            }
        }
        int ans=-1e9;
        for(int i=1; i<=n; i++){
            if(time[i]==1e9){
                return -1;
            }
            ans=max(ans,time[i]);
        }
        return ans;
    }
};