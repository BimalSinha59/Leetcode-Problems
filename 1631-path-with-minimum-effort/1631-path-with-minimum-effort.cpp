class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        dist[0][0]=0;
        int di[]={-1,0,1,0};
        int dj[]={0,1,0,-1};
        while(!pq.empty()){
            int dis=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            if(i==n-1 && j==m-1){
                return dis;
            }
            for(int k=0; k<4; k++){
                int ni=i+di[k];
                int nj=j+dj[k];
                if(ni>=0 && ni<n && nj>=0 && nj<m){
                    if(max(abs(heights[i][j]-heights[ni][nj]),dis)<dist[ni][nj]){
                        dist[ni][nj]=max(abs(heights[i][j]-heights[ni][nj]),dis);
                        pq.push({dist[ni][nj],{ni,nj}});
                    }
                }
            }
        }
        return 0;
    }
};