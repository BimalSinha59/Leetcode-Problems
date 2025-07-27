class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=1,k=2;
        int ans=0;
        while(j<n){
            if(k<n && nums[j]>nums[i] && nums[j]>nums[k] || nums[j]<nums[i] && nums[j]<nums[k]){
                ans++;
                i=j;
                j++;
                k++;
            }
            else if(nums[j]==nums[k]){
                j++;
                k++;
            }
            else{
                i++;
                j++;
                k++;
            }
        }
        return ans;
    }
};