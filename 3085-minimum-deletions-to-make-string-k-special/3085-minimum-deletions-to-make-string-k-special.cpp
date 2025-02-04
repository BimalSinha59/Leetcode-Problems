class Solution {
public:
    int minimumDeletions(string word, int k) {
        int n=word.size();
        map<char,int>mp;
        for(int i=0; i<n; i++){
            mp[word[i]]++;
        }
        vector<int>v;
        for(auto it:mp){
            v.push_back(it.second);
        }
        sort(v.begin(),v.end());
       
        int ans=INT_MAX;
        int maxF=v.back();
        for(int i=1; i<=maxF; i++){
            int count=0;
            for(int j=0; j<v.size(); j++){
                if(v[j]>i+k){
                    count+=v[j]-i-k;
                }
                else if(v[j]<i){
                    count+=v[j];
                }
            }
            ans=min(ans,count);
        }

        return ans;
        
    }
};