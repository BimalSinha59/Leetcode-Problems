class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;
        for(int i=0; i<n; i++){
            if(nums[i]>0){
                mp[nums[i]]++;
            }
            
        }
        if(mp.empty()){
            return *max_element(nums.begin(),nums.end());
        }
        else{
            int ans=0;
             for(auto it:mp){
                 ans+=it.first;
             }
            return ans;
            
        }
        
    }
};