class Solution {
public:

    bool isSort(vector<int>&nums,int s,int k){
        for(int i=s; i<s+k-1; i++){
            if(nums[i]>=nums[i+1]){
                return false;
            }
        }
        return true;
    }
    
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<2*k) return false;
        for(int i=0; i<=n-2*k; i++){
            vector<pair<int,int>>v;
            if(isSort(nums,i,k) && (isSort(nums,i+k,k))){
                return true;
            }
        }
        return false;
    }
};