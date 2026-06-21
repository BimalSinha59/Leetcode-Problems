class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = *max_element(costs.begin(), costs.end()) + 1;
        vector<int> count(n, 0);
        for (int& cost : costs) {
            count[cost]++;
        }
        int m = costs.size();
        vector<int> sortedCosts(m);
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (count[i]--) {
                sortedCosts[j] = i;
                j++;
            }
            if (j == m) {
                break;
            }
        }
        int maxIceCreamBars = 0;
        for (int& cost : sortedCosts) {
            if (coins >= cost) {
                maxIceCreamBars++;
                coins -= cost;
            } else {
                break;
            }
        }
        return maxIceCreamBars;
    }
};