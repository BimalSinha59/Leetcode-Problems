class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size(),m=p.size();
        unordered_map<int,int>mp1,mp2;
        for(auto it:p){
            mp1[it]++;
        }
        for(int i=0; i<m; i++){
            mp2[s[i]]++;
        }
        vector<int>ans;
        if(mp1==mp2){
            ans.push_back(0);
        }
        for(int i=m; i<n; i++){
            mp2[s[i-m]]--;
            if(mp2[s[i-m]]==0){
                mp2.erase(s[i-m]);
            }
            mp2[s[i]]++;
            if(mp1==mp2){
                ans.push_back(i-m+1);
            }
        }
        return ans;
    }
};