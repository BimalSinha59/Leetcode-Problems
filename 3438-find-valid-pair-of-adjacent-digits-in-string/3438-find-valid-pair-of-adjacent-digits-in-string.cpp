class Solution {
public:
    string findValidPair(string s) {
        int n=s.size();
        map<char,int>mp;
        for(int i=0; i<n; i++){
            mp[s[i]]++;
        }

        string ans="";
        for(int i=1; i<n; i++){
            int x=s[i-1]-'0';
            int y=s[i]-'0';

            if(mp[s[i-1]]==x && mp[s[i]]==y && s[i-1]!=s[i]){
                ans+=s[i-1];
                ans+=s[i];
                break;
            }
        }
        return ans;
    }
};