class Solution {
public:
    int distinctPoints(string s, int k) {
        int n=s.size();
        int fx=0,fy=0;
        for(int i=0; i<n; i++){
            if(s[i]=='U'){
                fy++;
            }
            else if(s[i]=='D'){
                fy--;
            }
            else if(s[i]=='L'){
                fx--;
            }
            else{
                fx++;
            }
        }
        set<pair<int,int>>st;
        for(int i=0; i<k; i++){
            if(s[i]=='U'){
                fy--;
            }
            else if(s[i]=='D'){
                fy++;
            }
            else if(s[i]=='L'){
                fx++;
            }
            else{
                fx--;
            }
        }
        st.insert({fx,fy});
        for(int i=k; i<n; i++){
            if(s[i-k]=='U'){
                fy++;
            }
            else if(s[i-k]=='D'){
                fy--;
            }
            else if(s[i-k]=='L'){
                fx--;
            }
            else if(s[i-k]=='R'){
                fx++;
            }
            if(s[i]=='U'){
                fy--;
            }
            else if(s[i]=='D'){
                fy++;
            }
            else if(s[i]=='L'){
                fx++;
            }
            else{
                fx--;
            }
            st.insert({fx,fy});
        }
        return (int)st.size();
    }
};