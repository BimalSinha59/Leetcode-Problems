class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0;
        int ans=1e9;
        int sum=0;
        while(j<n){
            sum+=nums[j];
            if(sum>=target){
                while(sum>=target){
                    ans=min(ans,j-i+1);
                    sum-=nums[i];
                    i++;
                }
            }
            j++;
        }
        if(ans==1e9){
            return 0;
        }
        return ans;
    }
};