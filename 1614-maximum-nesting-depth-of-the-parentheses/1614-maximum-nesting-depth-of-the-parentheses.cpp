class Solution {
public:
    int maxDepth(string s) {
        int n=s.size();
        int ans=0;
        string temp="";
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                temp+=s[i];
                ans=max(ans,(int)temp.size());
            }
            else if(s[i]==')'){
                temp.pop_back();
            }
        }

        return ans;
        
    }
};