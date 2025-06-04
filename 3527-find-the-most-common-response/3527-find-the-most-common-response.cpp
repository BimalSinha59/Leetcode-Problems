class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        int n=responses.size();
        vector<vector<string>>dup;
        for(int i=0; i<n; i++){
            vector<string>temp;
            unordered_set<string>st;
            for(int j=0; j<responses[i].size(); j++){
                if(st.find(responses[i][j])==st.end()){
                    temp.push_back(responses[i][j]);
                    st.insert(responses[i][j]);
                }
            }
            dup.push_back(temp);
        }
        map<string,int>mp;
         for(int i=0; i<n; i++){
           
            for(int j=0; j<dup[i].size(); j++){
                mp[dup[i][j]]++;
            }
            
        }
        vector<string>ans;
        int maxi=0;
        for(auto it:mp){
            maxi=max(maxi,it.second);
        }
        for(auto it:mp){
            if(it.second==maxi){
                ans.push_back(it.first);
            }
        }
        if(ans.size()==1){
            return ans[0];
        }
        sort(ans.begin(),ans.end());
        return ans[0];

    }
};