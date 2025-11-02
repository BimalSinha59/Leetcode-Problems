class Solution {
public:
    void dfs(int i,int j, int ai, int aj, int m, int n, vector<vector<int>>& vis){
        int ni=i+ai;
        int nj=j+aj;
        if(ni>=0 && ni<m && nj>=0 && nj<n && vis[ni][nj]!=2 && vis[ni][nj]!=3){
            vis[ni][nj]=1;
            dfs(ni,nj,ai,aj,m,n,vis);
        }
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(auto& it:guards){
            vis[it[0]][it[1]]=2;
        }
        for(auto& it:walls){
            vis[it[0]][it[1]]=3;
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(vis[i][j]==2){
                    dfs(i,j,0,1,m,n,vis);
                    dfs(i,j,0,-1,m,n,vis);
                    dfs(i,j,1,0,m,n,vis);
                    dfs(i,j,-1,0,m,n,vis);
                }
            }
        }
        int ans=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(vis[i][j]==0){
                    ans++;
                }
            }
        }
        return ans;
    }
};