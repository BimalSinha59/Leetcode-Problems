class Solution {
public:
    int sumOfPrimesInRange(int n) {
        string str = to_string(n);
        reverse(str.begin(), str.end());
        int r = stoi(str);
        int sum = 0;
        for (int i = (min(r, n) == 1 ? 2 : min(r, n)); i <= max(r, n); i++) {
            bool isPrime = true;
            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime) {
                sum += i;
            }
        }
        return sum;
    }
};