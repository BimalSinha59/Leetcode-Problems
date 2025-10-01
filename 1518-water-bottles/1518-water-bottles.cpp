class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        while (numBottles > 0) {
            ans += numBottles / numExchange;
            int rem = numBottles % numExchange;
            numBottles /= numExchange;
            if (numBottles == 0) {
                break;
            }
            numBottles += rem;
        }
        return ans;
    }
};