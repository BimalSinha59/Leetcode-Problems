class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 1;
        for (int i = 0; i < n; i++) {
            vector<int>freq(26,0);
            int maxi=0;
            int de=0;
            for (int j = i; j < n; j++) {
                freq[s[j]-'a']++;
                if(freq[s[j]-'a']==1){
                    de++;
                }
                maxi=max(maxi,freq[s[j]-'a']);
                if(de*maxi==(j-i+1)){
                    ans=max(ans,de*maxi);
                }
            }
        }
        return ans;
    }
};