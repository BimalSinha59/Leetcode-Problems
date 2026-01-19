class Solution {
public:
    string lexSmallestAfterDeletion(string s) {
        int n=s.size();
        vector<char>smin(n);
        smin[n-1]=s[n-1];
        for(int i=n-2; i>=0; i--){
            smin[i]=min(smin[i+1],s[i]);
        }
        map<char,int>mp;
        for(char &ch:s){
            mp[ch]++;
        }
        for(int i=0; i<n-1; i++){
            if(mp[s[i]]>1 && smin[i+1]<s[i]){
                mp[s[i]]--;
                s[i]='$';
            }
        }
        while(mp[s.back()]>1){
            mp[s.back()]--;
            s.pop_back();
        }
        string ans;
        for(char &ch:s){
            if(ch!='$'){
                ans.push_back(ch);
            }
        }
        return ans;
    }
};