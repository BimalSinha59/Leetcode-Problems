class Solution {
public:
    int totalMoney(int n) {
        int div = n / 7;
        int sum = (7 * 8) / 2;
        int sts = 0, eds = 0;
        int ans = 0;
        int add1 = 1, add2 = 8;
        for (int i = 0; i < div; i++) {
            ans += (sum - sts + eds);
            sts += add1;
            eds += add2;
            add1++;
            add2++;
        }
        int rem = n % 7;
        for (int i = 0; i < rem; i++) {
            ans += add1;
            add1++;
        }
        return ans;
    }
};