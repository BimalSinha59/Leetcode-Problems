class Solution {
public:
    int maxDifference(string s) {
        int n=s.size();
        map<char,int>mp;
        for(int i=0; i<n; i++){
            mp[s[i]]++;
        }

        vector<int>vo,ve;
        for(auto it:mp){
            int x=it.second;
            if(x&1)
               vo.push_back(x);
            else{
                ve.push_back(x);
            }
        }
        int mo=vo.size();
        int me=ve.size();
        
        int maxA=INT_MIN;
        for(int i=0; i<mo; i++){
            for(int j=0; j<me; j++){
                maxA=max(maxA,vo[i]-ve[j]);
            }
        }

        return maxA;
        
        
    }
};