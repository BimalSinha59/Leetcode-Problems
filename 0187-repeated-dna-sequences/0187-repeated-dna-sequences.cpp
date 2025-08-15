class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.size();
        if(n<=10){
            return {};
        }
        unordered_map<string,int>mp;
        for(int i=0; i<=n-10; i++){
            string str=s.substr(i,10);
            mp[str]++;
        }
        vector<string> ans;
        for(auto it:mp){
            if(it.second>1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};