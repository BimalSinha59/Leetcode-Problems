class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        vector<pair<int,int>>v;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        for(auto it:mp){
            v.push_back({it.second,it.first});
        }
        sort(v.rbegin(),v.rend());
        vector<int>ans;
        for(int i=0; i<k; i++){
            ans.push_back(v[i].second);
        }
        return ans;
    }
};