class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles;
        while (numBottles > 0) {
            int remg = numBottles - numExchange;
            if (remg < 0) {
                break;
            }
            ans++;
            remg++;
            numExchange++;
            numBottles = remg;
        }
        return ans;
    }
};