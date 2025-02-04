class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        map<char,int>mp;
        for(int i=0; i<n; i++){
            mp[word[i]]++;
        }
        vector<int>v;
        for(auto it:mp){
            v.push_back(it.second);
        }
        sort(v.rbegin(),v.rend());
        int ans=0;
        int m=v.size();
        for(int i=0; i<min(m,8); i++){
            ans+=v[i];
        }
        for(int i=8; i<min(m,16); i++){
            ans+=2*v[i];
        }
        for(int i=16; i<min(m,24); i++){
            ans+=3*v[i];
        }
        for(int i=24; i<min(m,26); i++){
            ans+=4*v[i];
        }
        return ans;
    }
};