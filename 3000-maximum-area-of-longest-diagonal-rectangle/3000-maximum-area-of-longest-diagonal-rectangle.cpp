class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxArea=0;
        int maxDiag=0;
        for(auto it:dimensions){
            int l=it[0];
            int w=it[1];
            int sod=l*l+w*w;
            if(sod==maxDiag){
                maxArea=max(maxArea,l*w);
            }
            else if(sod>maxDiag){
                maxArea=l*w;
                maxDiag=sod;
            }
        }
        return maxArea;
    }
};