class Solution {
public:
    long long removeZeros(long long n) {
        string s;
        while(n>0){
            int dig=n%10;
            if(dig!=0){
                s.push_back(dig+'0');
            }
            n/=10;
        }
        reverse(s.begin(),s.end());
        return stoll(s);
    }
};