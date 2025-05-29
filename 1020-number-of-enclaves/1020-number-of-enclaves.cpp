class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis,int di[],int dj[],int n, int m){
        vis[i][j]=1;
        for(int k=0; k<4; k++){
            int ni=i+di[k];
            int nj=j+dj[k];
            if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]==1 && vis[ni][nj]==0){
                dfs(ni,nj,grid,vis,di,dj,n,m);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int di[]={-1,0,1,0};
        int dj[]={0,1,0,-1};
        for(int j=0; j<m; j++){
            if(grid[0][j]==1 && vis[0][j]==0){
                dfs(0,j,grid,vis,di,dj,n,m);
            }
            if(grid[n-1][j]==1 && vis[n-1][j]==0){
                dfs(n-1,j,grid,vis,di,dj,n,m);
            }
        }
        for(int i=0; i<n; i++){
            if(grid[i][0]==1 && vis[i][0]==0){
                dfs(i,0,grid,vis,di,dj,n,m);
            }
            if(grid[i][m-1]==1 && vis[i][m-1]==0){
                dfs(i,m-1,grid,vis,di,dj,n,m);
            }
        }
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    ans++;
                }
            }
        }
        return ans;
    }
};