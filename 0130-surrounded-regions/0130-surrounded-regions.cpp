class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& vis,vector<vector<char>>& board,int di[],int dj[],int n,int m){
        vis[i][j]=1;
        for(int k=0; k<4; k++){
            int ni=i+di[k];
            int nj=j+dj[k];
            if(ni>=0 && ni<n && nj>=0 && nj<m && board[ni][nj]=='O' && vis[ni][nj]==0){
                dfs(ni,nj,vis,board,di,dj,n,m);
            }
        }

    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int di[]={-1,0,1,0};
        int dj[]={0,1,0,-1};
        for(int j=0; j<m; j++){
            if(board[0][j]=='O' && vis[0][j]==0){
                dfs(0,j,vis,board,di,dj,n,m);
            } 
            if(board[n-1][j]=='O' && vis[n-1][j]==0){
                dfs(n-1,j,vis,board,di,dj,n,m);
            }
        }
        for(int i=0; i<n; i++){
            if(board[i][0]=='O' && vis[i][0]==0){
                dfs(i,0,vis,board,di,dj,n,m);
            }
            if(board[i][m-1]=='O' && vis[i][m-1]==0){
                dfs(i,m-1,vis,board,di,dj,n,m);
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]=='O' && vis[i][j]==0){
                    board[i][j]='X';
                }
            }
        }
        
    }
};