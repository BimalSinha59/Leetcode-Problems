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
            if(ans.empty() && num[i]=='0'){
                continue;
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
            if(ans.empty() && num[j]=='0'){
                continue;
            }
            ans.push_back(num[j]);
        }
        if(ans==""){
            ans="0";
        }
        return ans;
    }
};