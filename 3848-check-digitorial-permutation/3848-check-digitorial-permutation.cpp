class Solution {
public:
    bool isDigitorialPermutation(int n) {
        long long sum = 0;
        int num = n;
        multiset<int> st1, st2;
        vector<int> fact(10, 0);
        fact[0] = 1;
        for (int i = 1; i <= 9; i++) {
            fact[i] = i * fact[i - 1];
        }
        while (n > 0) {
            int dig = n % 10;
            sum = sum + 1LL * fact[dig];
            st1.insert(dig);
            n /= 10;
        }
        while (sum > 0) {
            int dig = sum % 10;
            st2.insert(dig);
            sum /= 10;
        }
        return st1 == st2;
    }
};