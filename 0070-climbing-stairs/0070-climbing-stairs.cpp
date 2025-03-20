class Solution {
public:
    // int f(int n){
    //     if(n<=2){
    //         return n;
    //     }
    //     return f(n-1)+f(n-2);
    // }
    int climbStairs(int n) {
        //return f(n);
        if(n<=2){
            return n;
        }
        int prev2=1;
        int prev=2;
        for(int i=3; i<=n; i++){
            int curri=prev+prev2;
            prev2=prev;
            prev=curri;
        }
        return prev;
    }
};