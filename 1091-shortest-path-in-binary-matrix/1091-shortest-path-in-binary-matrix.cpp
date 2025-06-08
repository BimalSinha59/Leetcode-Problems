class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1){
            return -1;
        }
        int n=grid.size();
        if(n==1){
            return 1;
        }
        queue<pair<pair<int,int>,int>>q; //No need of priority queue
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        q.push({{0,0},0});
        dist[0][0]=0;
        int ans=1e9;
        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int dis=q.front().second;
            q.pop();
            for(int di=-1; di<=1; di++){
                for(int dj=-1; dj<=1; dj++){
                    if(di==0 && dj==0){
                        continue;
                    }
                    int ni=i+di;
                    int nj=j+dj;
                    if(ni>=0 && ni<n && nj>=0 && nj<n && grid[ni][nj]==0 ){
                        if(ni==n-1 && nj==n-1){
                            ans=min(ans,dis+1);
                        }
                        if(dis+1<dist[ni][nj]){
                            dist[ni][nj]=dis+1;
                            q.push({{ni,nj},dis+1});
                        }
                    }
                }
            }
        }
        if(ans==1e9){
            return -1;
        }
        return ans+1;
    }
};