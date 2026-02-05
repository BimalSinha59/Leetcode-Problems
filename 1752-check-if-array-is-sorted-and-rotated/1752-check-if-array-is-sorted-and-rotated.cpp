class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int idx=-1;
        while(i+1<n){
            if(nums[i]>nums[i+1]){
                idx=i+1;
                break;
            }
            i++;
        }
        if(idx==-1){
            return true;
        }
        for(int i=idx; i<n; i++){
            if(nums[i]>nums[0] || (i+1<n && nums[i]>nums[i+1])){
                return false;
            }
        }
        return true;
    }
};