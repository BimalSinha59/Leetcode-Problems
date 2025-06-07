class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        int n=x.size();
        map<int,vector<int>>mp;
        for(int i=0; i<n; i++){
            mp[x[i]].push_back(i);
        }
        vector<int>v;
        for(auto it:mp){
           auto arr=it.second;
           int maxi=-1;
           for(int i=0; i<arr.size(); i++){
              maxi=max(maxi,y[arr[i]]);
           }
           v.push_back(maxi);
        }
        if(v.size()<3){
            return -1;
        }
        sort(v.rbegin(),v.rend());
        return v[0]+v[1]+v[2];
    }
};