class Solution {
public:
    int romanToInt(string s) {
        int ans=0;
        unordered_map<char,int>mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        int n=s.size();
        ans+=mp[s[0]];
        for(int i=1; i<n; i++){
            if(s[i]=='V' && s[i-1]=='I'){
                ans+=4-mp[s[i-1]];
            }
            else if(s[i]=='X' && s[i-1]=='I'){
                ans+=9-mp[s[i-1]];
            }
            else if(s[i]=='L' && s[i-1]=='X'){
                ans+=40-mp[s[i-1]];
            }
            else if(s[i]=='C' && s[i-1]=='X'){
                ans+=90-mp[s[i-1]];
            }
            else if(s[i]=='D' && s[i-1]=='C'){
                ans+=400-mp[s[i-1]];
            }
            else if(s[i]=='M' && s[i-1]=='C'){
                ans+=900-mp[s[i-1]];
            }
            else{
                ans+=mp[s[i]];
            }
        }
        return ans;
    }
};