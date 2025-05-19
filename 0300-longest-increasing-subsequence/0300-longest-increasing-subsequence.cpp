class Solution {
public:
    int f(int ind,int p_end,vector<int>& nums, int n,vector<vector<int>> &dp){
        if(ind==n){
            return 0;
        }
        if(dp[ind][p_end+1]!=-1){
            return dp[ind][p_end+1];
        }
        int len=1;
        len = 0+f(ind+1,p_end,nums,n,dp);
        if(p_end==-1 || nums[ind]>nums[p_end]){
            len=max(len,1+f(ind+1,ind,nums,n,dp));
        }
        return  dp[ind][p_end+1]=len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // return f(0,-1,nums,n,dp);

        vector<int>temp;
        int len=1;
        temp.push_back(nums[0]);
        for(int i=1; i<n; i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
                len++;
            }
            else{
                int idx=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[idx]=nums[i];
            }
            
        }
        return len;
    }
};