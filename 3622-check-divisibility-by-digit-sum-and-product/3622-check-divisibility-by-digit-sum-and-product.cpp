class Solution {
public:
    bool checkDivisibility(int n) {
        int s=0,p=1;
        int nn=n;
        while(nn>0){
            int dig=nn%10;
            s+=dig;
            p*=dig;
            nn/=10;
        }
        int sum=s+p;
        return n%sum==0;
    }
};