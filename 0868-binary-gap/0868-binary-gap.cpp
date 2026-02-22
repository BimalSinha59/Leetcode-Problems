class Solution {
public:
    int binaryGap(int n) {
        int ans = 0;
        int lone = -1;
        int cnt = 0;
        while (n > 0) {
            int dig = n % 2;
            if (dig == 1) {
                if (lone != -1) {
                    ans = max(ans, cnt - lone);
                }
                lone = cnt;
            }
            cnt++;
            n /= 2;
        }
        return ans;
    }
};