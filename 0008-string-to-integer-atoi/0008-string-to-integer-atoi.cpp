class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        int i=0;
        while(s[i]==' '){
            i++;
        }
        bool ng=false;
        if(s[i]=='-'){
            ng=true;
            i++;
        }
        else if(s[i]=='+'){
            i++;
        }
        while(s[i]=='0'){
            i++;
        }
        vector<int>v;
        for(i=i; i<n; i++){
            if(s[i]>='0' && s[i]<='9'){
               v.push_back(s[i]-'0');
            }
            else{
                break;
            }
        }

        long long mul=1;
        long long ans=0;
        for(int j=v.size()-1; j>=0; j--){
            ans+=v[j]*mul;
            mul*=10;
            if(ng && -ans<=INT_MIN){
                ans=INT_MIN;
                break;
            }
            else if(ans>=INT_MAX){
                ans=INT_MAX;
                break;
            }
        }
        if(ng && ans!=0){
            return -ans;
        }
        return (int)ans;
        
    }
};