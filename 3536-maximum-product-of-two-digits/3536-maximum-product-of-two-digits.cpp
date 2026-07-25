class Solution {
public:
    int maxProduct(int n) {
        int maxProduct = 0;
        int maxi = -1;
        while (n > 0) {
            int digit = n % 10;
            n /= 10;
            if (maxi != -1) {
                maxProduct = max(maxProduct, maxi * digit);
            }
            maxi = max(maxi, digit);
        }
        return maxProduct;
    }
};