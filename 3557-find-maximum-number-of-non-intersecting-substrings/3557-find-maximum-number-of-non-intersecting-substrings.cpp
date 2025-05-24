class Solution {
public:
    int maxSubstrings(string word) {
        int n=word.size();
        vector<int>v(26,-1);
        int ans=0;
        for(int i=0; i<n; i++){
            int ind=word[i]-'a';
            if(v[ind]!=-1 && i-v[ind]>=3){
                ans++;
                for(int i=0; i<26; i++){
                    v[i]=-1;
                }
            }
            else{
                if(v[ind]==-1){
                    v[ind]=i;
                }
            }
        }
        return ans;
    }
};