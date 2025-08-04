class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s==""){
            return 0;
        }
        int n=s.size();
        int ans=INT_MIN;
        map<char,int> mp;
        int i=0,j=0;
        for(j=0,i=j; j<n,i<n;){
            
            if(mp.find(s[i])==mp.end()){
                mp[s[i]]++;
                int x=mp.size();
                ans=max(ans,x);
                i++;
            }
            else{
                mp.clear();
                j++;
                i=j;

            }
        }
        return ans;
    }
};