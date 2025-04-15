class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        int num = n;
        int c = 0;
        while (num > 0) {
            c++;
            num /= 2;
        }

        int x = (1 << c) - 1;
        if (n <= 2) {
            return n;
        }
        return x + 1;
    }
};