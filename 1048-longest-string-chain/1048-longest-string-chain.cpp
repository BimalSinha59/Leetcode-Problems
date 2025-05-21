class Solution {
public:
    static bool comp(string &s1,string &s2){
        return s1.size()<s2.size();
    }
    bool checkPredecessor(string &s1,string &s2){
        int n=s1.size(),m=s2.size();
        if(n!=m+1){
            return false;
        }
        int idx1=0,idx2=0;
        while(idx1<n){
            if(s1[idx1]==s2[idx2]){
                idx1++;
                idx2++;
            }
            else{
                idx1++;
            }
        }
        if(idx1==n && idx2==m){
            return true;
        }
        return false;
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(), comp);
        // for(auto it:words){
        //     cout<<it<<" ";
        // }
        int maxi=1;
        vector<int>dp(n,1);
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(checkPredecessor(words[i],words[j]) && 1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};