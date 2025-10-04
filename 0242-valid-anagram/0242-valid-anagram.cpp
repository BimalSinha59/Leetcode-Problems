class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size(),m=t.size();
        if(n!=m){
            return false;
        }
        vector<int>mp(26,0);
        for(int i=0; i<n; i++){
            mp[s[i]-'a']++;
        }
        for(int i=0; i<n; i++){
            mp[t[i]-'a']--;
        }
        for(int i=0; i<26; i++){
            if(mp[i]!=0){
                return false;
            }
        }
        return true;
    }
};