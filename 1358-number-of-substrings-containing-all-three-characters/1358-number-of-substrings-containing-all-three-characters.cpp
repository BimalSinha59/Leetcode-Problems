class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int hash[3]={-1,-1,-1};
        int ans=0;
        for(int i=0; i<n; i++){
            hash[s[i]-'a']=i;
            ans+=(min(hash[0],min(hash[1],hash[2]))+1);
        }
        return ans;
    }
};