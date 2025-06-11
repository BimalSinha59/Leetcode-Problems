class Solution {
public:
    vector<int> dijkstra(vector<pair<int,int>> adj[],int source,int n){
        vector<int>dist(n,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,source});
        dist[source]=0;
        while(!q.empty()){
            int dis=q.top().first;
            int node=q.top().second;
            q.pop();
            for(auto it:adj[node]){
                int adjNode=it.first;
                int ewt=it.second;
                if(dis+ewt<dist[adjNode]){
                    dist[adjNode]=dis+ewt;
                    q.push({dis+ewt,adjNode});
                }
            }
        }
        return dist;

    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        ///****1.Using Floyed Warshall Algo****///

        // vector<vector<int>>dist(n,vector<int>(n,1e9));
        // for(int i=0; i<edges.size(); i++){
        //     int u=edges[i][0];
        //     int v=edges[i][1];
        //     int wt=edges[i][2];
        //     dist[u][v]=wt;
        //     dist[v][u]=wt;
        // }
        // for(int k=0; k<n; k++){
        //     for(int i=0; i<n; i++){
        //         for(int j=0; j<n; j++){
        //             if(i==j){
        //                 dist[i][i]=0;
        //                 continue;
        //             }
        //             else if(dist[i][k]==1e9 || dist[k][j]==1e9){
        //                 continue;
        //             }
        //             else{
        //                 dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
        //             }
        //         }
        //     }
        // }
        // int maxCity=n;
        // int cityNo=-1;
        // for(int i=0; i<n; i++){
        //     int cnt=0;
        //     for(int j=0; j<n; j++){
        //         if(dist[i][j]<=distanceThreshold){
        //             cnt++;
        //         }
        //     }
        //     if(cnt<=maxCity){
        //         cityNo=i;
        //         maxCity=cnt;
        //     }
        // }
        // return cityNo;


        ///****2. Using Dijkstra's Algo*****///

        vector<pair<int,int>>adj[n];
        for(int i=0; i<edges.size(); i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        vector<vector<int>>dist;
        for(int i=0; i<n; i++){
            auto v = dijkstra(adj,i,n);
            dist.push_back(v);
        }

        int maxCity=n;
        int cityNo=-1;
        for(int i=0; i<n; i++){
            int cnt=0;
            for(int j=0; j<n; j++){
                if(dist[i][j]<=distanceThreshold){
                    cnt++;
                }
            }
            if(cnt<=maxCity){
                cityNo=i;
                maxCity=cnt;
            }
        }
        return cityNo;
    }
};