class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for (int& num : nums) {
            int cnt = 0;
            int fd;
            for (int i = 2; i * i <= num; i++) {
                if (num % i == 0) {
                    fd = i;
                    cnt++;
                }
                if (cnt > 1) {
                    cnt = 2;
                    break;
                }
            }
            if (cnt == 1 && fd != num / fd) {
                ans += (1 + fd + num / fd + num);
            }
        }
        return ans;
    }
};