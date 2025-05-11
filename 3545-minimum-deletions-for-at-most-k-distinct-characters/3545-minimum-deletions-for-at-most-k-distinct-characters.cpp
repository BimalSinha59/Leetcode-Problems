class Solution {
public:
    int minDeletion(string s, int k) {
        int n=s.size();
        map<char,int>mp;
        for(int i=0; i<n; i++){
            mp[s[i]]++;
        }
        vector<pair<int,int>>v;
        for(auto it:mp){
            v.push_back({it.second,it.first});
        }
        sort(v.begin(),v.end());

        
        int cnt=mp.size();
        int rem=cnt-k;
        int ans=0;
        if(rem>0){
            for(int i=0; i<rem; i++){
                ans+=v[i].first;
            }
        }
        return ans;
        
    }
};