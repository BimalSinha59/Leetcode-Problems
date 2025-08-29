class Solution {
public:
    long long flowerGame(int n, int m) {
        int on=ceil(n/2.0);
        int om=ceil(m/2.0);
        int en=n-on;
        int em=m-om;
        long long ans=(on*1LL*em)+(om*1LL*en);
        return ans;
    }
};