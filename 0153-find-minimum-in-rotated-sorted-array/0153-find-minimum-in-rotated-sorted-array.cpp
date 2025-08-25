class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int s=0,e=n-1,ans=1e9;
        while(s<=e){
            int mid=(s+e)/2;
            ans=min(ans,nums[mid]);
            if(nums[s]<=nums[mid]){
                if(nums[mid]>nums[e]){
                    s=mid+1;
                }
                else{
                    e=mid-1;
                }
            }
            else{
                e=mid-1;
            }
        }
        return ans;
    }
};