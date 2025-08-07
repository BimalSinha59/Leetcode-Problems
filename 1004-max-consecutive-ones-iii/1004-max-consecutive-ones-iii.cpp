class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0,r=0;
        int ans=0;
        int zs=0;
        while(r<n){
            if(nums[r]==0){
                zs++;
            }
            if(zs<=k){
                int len=r-l+1;
                ans=max(ans,len);
            }
            else{
                while(l<n && zs>k){
                    if(nums[l]==0){
                        zs--;
                    }
                    l++;
                }
            }
            r++;
        }
        return ans;
    }
};