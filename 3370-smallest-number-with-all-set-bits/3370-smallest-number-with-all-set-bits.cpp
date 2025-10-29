class Solution {
public:
    int smallestNumber(int n) {
        int pw=0;
        int ans=0;
        while(n>0){
            n/=2;
            ans+=(1<<pw);
            pw++;
        }
        return ans;
    }
};