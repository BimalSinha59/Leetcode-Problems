class Solution {
public:
    bool reorderedPowerOf2(int n) {
        if((n&(n-1))==0){
            return true;
        }
        int num=1;
        vector<map<int,int>>v;
        while(true){
            int nnum=num;
            map<int,int>mp;
            while(nnum>0){
                int dig=nnum%10;
                mp[dig]++;
                nnum/=10;
            }
            v.push_back(mp);
            num*=2;
            if(num>1e9){
                break;
            }
        }
        map<int,int>mpp;
        while(n>0){
            int dig=n%10;
            mpp[dig]++;
            n/=10;
        }
        for(int i=0; i<v.size(); i++){
            if(v[i]==mpp){
                return true;
            }
        }
        return false;
    }
};