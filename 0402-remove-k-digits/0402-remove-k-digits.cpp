class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        string ans;
        int i;
        for(i=0; i<n; i++){
            while(!ans.empty() && ans.back()>num[i]){
                ans.pop_back();
                k--;
                if(k==0){
                    break;
                }
            }
            if(k==0){
                break;
            }
            ans.push_back(num[i]);
        }
        if(k!=0){
            while(!ans.empty() && k!=0){
                ans.pop_back();
                k--;
            }
        }
        for(int j=i; j<n; j++){
            ans.push_back(num[j]);
        }
        i=0;
        while(ans[i]=='0'){
            i++;
        }
        string finalAns="";
        for(int j=i; j<ans.size(); j++){
            finalAns.push_back(ans[j]);
        }
        if(finalAns==""){
            finalAns="0";
        }
        return finalAns;
    }
};