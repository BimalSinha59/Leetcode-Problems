class Solution {
public:
    string largestGoodInteger(string num) {
        char ch;
        int maxi=-1;
        for(int i=1; i<num.size()-1; i++){
            if(num[i-1]==num[i] && num[i]==num[i+1]){
                if((num[i]-'0')>maxi){
                    ch=num[i];
                    maxi=num[i]-'0';
                }
            }
        }
        if(maxi==-1){
            return "";
        }
        string ans;
        for(int i=0; i<3; i++){
            ans.push_back(ch);
        }
        return ans;
    }
};