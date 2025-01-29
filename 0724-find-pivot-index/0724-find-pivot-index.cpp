class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return 0;
        }
        int psuml[n];
        int psumr[n];
        psuml[0]=nums[0];
        psumr[n-1]=nums[n-1];
        for(int i=1; i<n; i++){
            psuml[i]=psuml[i-1]+nums[i];
        }
        for(int i=n-2; i>=0; i--){
            psumr[i]=psumr[i+1]+nums[i];
        }

        if(psumr[1]==0){
            return 0;
        }
        for(int i=1; i<n-1; i++){
            if(psuml[i-1]==psumr[i+1]){
              return i;
            }
        }

        if(psuml[n-2]==0){
            return n-1;
        }
        return -1;
        
    }
};