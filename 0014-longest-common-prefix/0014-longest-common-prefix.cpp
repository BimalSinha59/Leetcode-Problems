class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string ans="";
        int minlen=INT_MAX;
        for(int i=0; i<n; i++){
            minlen=min(minlen,(int)strs[i].size());
        }
        bool temp=true;
        for(int i=0; i<minlen; i++){
           
            char ch = strs[0][i];
            for(int j=1; j<n; j++){
                if(strs[j][i]!=ch){
                    temp=false;
                    break;
                }
            }
            if(temp){
                ans+=ch;
            }
            else{
                break;
            }
        }
        return ans;
        
    }
};