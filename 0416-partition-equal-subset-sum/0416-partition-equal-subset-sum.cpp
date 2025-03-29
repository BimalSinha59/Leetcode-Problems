class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int tSum=0;
        for(int i=0; i<n ; i++){
            tSum+=nums[i];
        }
        if(tSum&1){
            return false;
        }
        int k=tSum/2;
        vector<bool>prev(k+1,0),curr(k+1,0);
        prev[0]=curr[0]=true;
        if(nums[0]<=k){
            prev[nums[0]]=true;
        }
        for(int idx=1; idx<n; idx++){
            for(int tgt=1; tgt<=k; tgt++){
                bool notTake=prev[tgt];
                bool take=false;
                if(nums[idx]<=tgt){
                    take=prev[tgt-nums[idx]];
                }
                curr[tgt]=take|notTake;

            }
            prev=curr;
        }
        return prev[k];
        
    }
};