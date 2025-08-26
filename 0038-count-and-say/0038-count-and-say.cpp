class Solution {
public:
    string solve(string res,int n){
        if(n==1) return res;

        string ans="";
        int i=0,j=0;
        while(i<res.size()){
            int c=0;
            while(j<res.size() && res[i]==res[j]){
                j++;
            }
            c=j-i;
            ans+=to_string(c);
            ans.push_back(res[i]);
            i=j;
        }
        return solve(ans,n-1);
    }
    string countAndSay(int n) {
        if(n==1) return "1";
        string res="1";
        return solve(res,n);
        
    }
};