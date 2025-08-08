class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int psum=0,ans=0;
        mp[0]=1;
        for(int i=0; i<n; i++){
            psum+=nums[i];
            int diff=psum-goal;
            ans+=mp[diff];
            mp[psum]++;
        }
        return ans;
    }
};