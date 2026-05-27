class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.size();
        int ans = 0;
        for (char ch='a' ; ch<='z'; ch++) {
            int lidx=-1;
            for(int i=n-1; i>=0; i--){
                if(word[i]==ch){
                    lidx=i;
                    break;
                }
            }
            int fidx=-1;
            for(int i=0; i<n; i++){
                if(word[i]==ch-'a'+'A'){
                    fidx=i;
                    break;
                }
            }
            if(lidx!=-1 && fidx!=-1 && lidx<fidx){
                ans++;
            }
        }
        return ans;
    }
};