class Solution {
public:
    bool isBalanced(int num) {
        vector<int> mp(10, 0);
        while (num > 0) {
            int dig = num % 10;
            mp[dig]++;
            num /= 10;
        }
        for (int i = 0; i < 10; i++) {
            if (mp[i] > 0 && i != mp[i]) {
                return false;
            }
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        for (int i = n + 1; i <= 1224444; i++) {
            if (isBalanced(i)) {
                return i;
            }
        }
        return 0;
    }
};