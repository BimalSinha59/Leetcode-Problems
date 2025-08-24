class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int l=0,ans=0,zs=0;
        for(int r=0; r<n; r++){
            if(nums[r]==0){
                zs++;
            }
            while(l<n && zs>1){
                if(nums[l]==0){
                    zs--;
                }
                l++;
            }
            ans=max(ans,r-l);
        }
        return ans;
    }
};