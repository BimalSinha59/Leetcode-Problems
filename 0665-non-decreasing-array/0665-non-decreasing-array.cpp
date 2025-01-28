class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int idx=0;
        for(int i=1; i<n; i++){
            if(nums[i-1]>nums[i]){
                idx=i-1;
                count++;
            }
        }
        if(count==0){
            return true;
        }
        else if(count==1){
            if(idx==0 || idx==n-2){
                return true;
            }
            else if((nums[idx+1]>=nums[idx-1]) || (nums[idx+2]>=nums[idx])){
                return true;
            }
           
        }
        return false;
    }
};