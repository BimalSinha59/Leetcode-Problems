class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>& grid,vector<vector<int>>& vis,int n,int m,int &ans,int dr[],int dc[]){
        vis[r][c]=1;
        ans++;
        for(int i=0; i<4; i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && vis[nr][nc]==0){
                dfs(nr,nc,grid,vis,n,m,ans,dr,dc);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        vector<vector<int>> vis(n,vector<int>(m,0));
        int maxArea=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j]==0 && grid[i][j]==1){
                    int ans=0;
                    dfs(i,j,grid,vis,n,m,ans,dr,dc);
                    maxArea=max(maxArea,ans);
                }
            }
        }
        return maxArea;
    }
};