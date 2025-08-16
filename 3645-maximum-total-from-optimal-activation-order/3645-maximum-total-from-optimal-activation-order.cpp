class Solution {
public:
    long long maxTotal(vector<int>& value, vector<int>& limit) {
        int n=value.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0; i<n; i++){
            mp[limit[i]].push_back(value[i]);
        }
        long long ans=0;
        for(auto it:mp){
            int lim=it.first;
            vector<int> v=it.second;
            sort(v.rbegin(),v.rend());
            for(int i=0; i<min(lim,(int)v.size()); i++){
                ans+=v[i];
            }
        }
        return ans;
    }
};