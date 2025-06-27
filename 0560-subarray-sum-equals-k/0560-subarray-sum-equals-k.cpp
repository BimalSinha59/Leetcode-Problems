class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int psum[n];
        psum[0]=nums[0];
        int ans=0;
        if(nums[0]==k){
            ans++;
        }
        unordered_map<int,int>mp;
        mp[0]=1;
        mp[nums[0]]++;
        for(int i=1; i<n; i++){
            psum[i]=psum[i-1]+nums[i];
            int diff = psum[i]-k;
            if(mp.find(diff)!=mp.end()){
                ans+=mp[diff];
            }
            mp[psum[i]]++;

        }
        return ans;
    }
};