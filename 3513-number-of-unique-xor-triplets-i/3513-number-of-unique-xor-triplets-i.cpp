class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            return n;
        }
        int bitLength = 0;
        while (n > 0) {
            bitLength++;
            n /= 2;
        }
        int uniqueXorTriplets = (1 << bitLength);
        return uniqueXorTriplets;
    }
};