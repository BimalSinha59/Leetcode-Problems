class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {

        int n=nums.size();
        int sum=0;
        int ans=INT_MIN;
        map<int,int>mp;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            mp[2*nums[i]]++;

        }

        for(int i=0; i<n; i++){
            int temp=sum-nums[i];
            if(mp[temp]>=2 || (mp[temp]==1 && temp!=2*nums[i])){
                ans=max(ans,nums[i]);
            }
        }
        return ans;
        
    }
};