class Solution {
public:
    int toINT(vector<int>& v){
        int n=v.size();
        int num=0;
        for(int i=0; i<n; i++){
            num=num*10+v[i];
        }
        return num;
    }
    int maximumSwap(int num) {
        int n=num;
        vector<int>v;
        while(n>0){
            int dig=n%10;
            v.push_back(dig);
            n/=10;
        }
        reverse(v.begin(),v.end());
        int ans=num;
        for(int i=0; i<v.size(); i++){
            for(int j=i+1; j<v.size(); j++){
                swap(v[i],v[j]);
                int nnum=toINT(v);
                ans=max(ans,nnum);
                swap(v[i],v[j]);
            }
        }
        return ans;
    }
};