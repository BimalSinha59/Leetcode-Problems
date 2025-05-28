class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>>vis=image;
        vis[sr][sc]=color;
        int iniColor=image[sr][sc];
        if(iniColor==color){
            return image;
        }
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        while(!q.empty()){
            int nr=q.front().first;
            int nc=q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int nrow=nr+dr[i];
                int ncol=nc+dc[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==iniColor){
                    vis[nrow][ncol]=color;
                    q.push({nrow,ncol});
                }
            }
        }
        return vis;
    }
};