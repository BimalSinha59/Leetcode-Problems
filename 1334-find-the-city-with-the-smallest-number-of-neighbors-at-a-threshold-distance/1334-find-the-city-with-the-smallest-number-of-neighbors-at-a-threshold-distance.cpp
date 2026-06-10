class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dis(n, vector<int>(n,1e9));
        for(int i=0; i<n; i++){
            dis[i][i]=0;
        }
        for(auto &edge:edges){
            int u=edge[0],v=edge[1],wt=edge[2];
            dis[u][v]=wt;
            dis[v][u]=wt;
        }
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    dis[i][j]=min(dis[i][j], dis[i][k]+dis[k][j]);
                }
            }
        }
        int cityNo=-1;
        int minReachables=n;
        for(int i=0; i<n; i++){
            int cnt=0;
            for(int j=0; j<n; j++){
                if(dis[i][j]<=distanceThreshold){
                    cnt++;
                }
            }
            if(cnt<=minReachables){
                minReachables=cnt;
                cityNo=i;
            }
        }
        return cityNo;
    }
};