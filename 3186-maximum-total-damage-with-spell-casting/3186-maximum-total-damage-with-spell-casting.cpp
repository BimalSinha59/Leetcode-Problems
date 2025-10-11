class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        int n=power.size();
        map<int,int>mp;
        for(auto it:power){
            mp[it]++;
        }
        vector<pair<int,int>>v;
        for(auto it:mp){
            v.push_back({it.first,it.second});
        }
        int m=v.size();
        vector<long long>pans(m,0);
        long long ans=0;
        for(int i=0; i<m; i++){
            pans[i]=v[i].first*1LL*v[i].second;
            int s=0,e=i;
            int idx=-1;
            while(s<=e){
                int mid=(s+e)/2;
                if(v[i].first-v[mid].first>2){
                    idx=mid;
                    s=mid+1;
                }     
                else{
                    e=mid-1;
                }    
            }
            if(idx!=-1){
                pans[i]+=pans[idx];
            }
            ans=max(ans,pans[i]);
            pans[i]=ans;
        }
        return ans;
    }
};