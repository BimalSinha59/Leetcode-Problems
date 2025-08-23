class Solution {
public:
    int maxEleIdx(vector<vector<int>>& mat, int mid, int n){
        int maxi=-1;
        int idx=-1;
        for(int i=0; i<n; i++){
            if(mat[i][mid]>maxi){
                maxi=mat[i][mid];
                idx=i;
            }
        }
        return idx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int s=0,e=m-1;
        while(s<=e){
            int mid=(s+e)/2;
            int row=maxEleIdx(mat,mid,n);
            int left=mid-1>=0 ? mat[row][mid-1] : -1;
            int right=mid+1<m ? mat[row][mid+1] : -1;
            if(mat[row][mid]>left && mat[row][mid]>right){
                return {row,mid};
            }
            else if(mat[row][mid]<left){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return {-1,-1};
    }
};