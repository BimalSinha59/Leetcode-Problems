class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        vector<int> hash(26,0);
        int l=0,maxi=0,ans=0;
        for(int r=0; r<n; r++){
            int idx=s[r]-'A';
            hash[idx]++;
            maxi=max(maxi,hash[idx]);
            int len=r-l+1;
            if(len-maxi<=k){
                ans=max(ans,len);
            }
            else{
                while(l<n && len-maxi>k){
                    hash[s[l]-'A']--;
                    for(int i=0; i<26; i++){
                        maxi=max(maxi,hash[i]);
                    }
                    l++;
                    len=r-l+1;
                }
            }
        }
        return ans;
    }
};