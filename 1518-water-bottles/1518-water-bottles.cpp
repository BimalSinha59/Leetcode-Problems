class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        while (numBottles > 0) {
            ans += numBottles / numExchange;
            numBottles /= numExchange;
            numBottles += numBottles % numExchange;
        }
        return ans;
    }
};