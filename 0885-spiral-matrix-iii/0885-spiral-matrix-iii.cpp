class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
       int c=0;
       int step=1;
       vector<vector<int>>ans;
       while(c!=rows*cols){
          for(int i=cStart;i<cStart+step; i++){
            if(rStart>=0 && rStart<rows && i>=0 && i<cols){
                ans.push_back({rStart,i});
                c++;
            }
          }
          //cout<<c<<" ";
          cStart+=step;

           for(int i=rStart;i<rStart+step; i++){
            if(i>=0 && i<rows && cStart>=0 && cStart<cols){
                ans.push_back({i,cStart});
                c++;
            }
          }
          //cout<<c<<" ";
          rStart+=step;
          step++;


           for(int i=cStart;i>cStart-step; i--){
            if(rStart>=0 && rStart<rows && i>=0 && i<cols){
                ans.push_back({rStart,i});
                c++;
            }
          }
          //cout<<c<<" ";
          cStart-=step;



           for(int i=rStart;i>rStart-step; i--){
            if(i>=0 && i<rows && cStart>=0 && cStart<cols){
                ans.push_back({i,cStart});
                c++;
            }
          }
          //cout<<c<<" ";
          rStart-=step;
          step++;


       }

       return ans;
        
    }
};