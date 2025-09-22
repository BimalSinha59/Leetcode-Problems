class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int ans=0;
        unordered_map<int,int>mp;
        int maxi=0;
        for(auto it:nums){
            mp[it]++;
            maxi=max(maxi,mp[it]);
        }
        for(auto it:mp){
            if(it.second==maxi){
                ans++;
            }
        }
        return ans*maxi;
    }
};