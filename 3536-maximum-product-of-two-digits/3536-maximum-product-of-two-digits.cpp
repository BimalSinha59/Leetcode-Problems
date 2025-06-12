class Solution {
public:
    int maxProduct(int n) {
        vector<int>v;
        while(n>0){
            int dig=n%10;
            v.push_back(dig);
            n/=10;
        }
        sort(v.begin(),v.end());
        int sz=v.size();
        return v[sz-1]*v[sz-2];
        
    }
};