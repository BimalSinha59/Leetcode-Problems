class Solution {
public:
    void dfs(int r,int c,vector<vector<char>>& grid,vector<vector<int>>& vis,int dr[],int dc[],int n, int m){
        vis[r][c]=1;
        for(int i=0; i<4; i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0 && grid[nr][nc]=='1'){
                dfs(nr,nc,grid,vis,dr,dc,n,m);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    dfs(i,j,grid,vis,dr,dc,n,m);
                    ans++;
                }
            }
        }
        return ans;
    }
};