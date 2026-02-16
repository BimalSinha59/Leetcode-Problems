class Solution {
public:
    int getSum(int a, int b) {
        int x;
        while(b!=0){
            x=(a&b);
            a=(a^b);
            b=(x<<1);
        }
        return a;
    }
};