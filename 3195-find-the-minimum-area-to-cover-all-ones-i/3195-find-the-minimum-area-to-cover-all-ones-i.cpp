class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int d1=1e9,d2=-1e9,l1=1e9,l2=-1e9;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    d1=min(d1,j);
                    d2=max(d2,j);
                    l1=min(l1,i);
                    l2=max(l2,i);
                }
            }
        }
        return (d2-d1+1)*(l2-l1+1);
    }
};