class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int ans=0;
        unordered_map<int,int>mp;
        int maxi=0;
        for(auto it:nums){
            mp[it]++;
            if(mp[it]>maxi){
                maxi=mp[it];
                ans=1;
            }
            else if(mp[it]==maxi){
                ans++;
            }
        }
        return ans*maxi;
    }
};