class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        double ans = INT_MIN;
        double pdt =1;

        for(int i=0; i<n; i++){
             pdt = pdt*nums[i];
             ans = max(ans, pdt);
             if(pdt==0){
                 pdt=1;
             }
         } 

          pdt =1;

        for(int i=n-1; i>=0; i--){
             pdt = pdt*nums[i];
             ans = max(ans, pdt);
             if(pdt==0){
                 pdt=1;
             }
         } 

    
     return ans;   
    }
};