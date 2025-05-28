class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size();
        int m=isWater[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(isWater[i][j]==1){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        vector<vector<int>>ans(n,vector<int>(m,0));
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int s=q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]!=1){
                    ans[nr][nc]=s+1;
                    vis[nr][nc]=1;
                    q.push({{nr,nc},s+1});
                }
            }
        }
        return ans;
    }
};