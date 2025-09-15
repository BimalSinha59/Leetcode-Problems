class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int n=text.size();
        int ans=0;
        set<char>st(brokenLetters.begin(),brokenLetters.end());
        for(int i=0; i<n; ){
            bool flg=true;
            while(i<n && text[i]!=' '){
                if(st.find(text[i])!=st.end()){
                    flg=false;
                }
                i++;
            }
            if(flg){
                ans++;
            }
            i++;
        }
        return ans;
    }
};