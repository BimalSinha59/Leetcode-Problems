class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1),hash(n,0);
        int maxi=1;
        int lIdx=0;
        sort(nums.begin(),nums.end());
        for(int i=1; i<n; i++){
            hash[i]=i;
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j]==0 && 1+dp[j]>dp[i]){
                    dp[i]=max(dp[i],1+dp[j]);
                    hash[i]=j;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                lIdx=i;
            }
        }
        // cout<<maxi<<" "<<lIdx<<endl;
        // for(auto it:hash){
        //     cout<<it<<" ";
        // }
        vector<int>ans;
        ans.push_back(nums[lIdx]);
        while(lIdx!=hash[lIdx]){
            ans.push_back(nums[hash[lIdx]]);
            lIdx=hash[lIdx];
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};