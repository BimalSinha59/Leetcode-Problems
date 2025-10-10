class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        int n = numWays.size();
        numWays.insert(numWays.begin(), 1);
        vector<int> ans;
        for (int i = 1; i <= n; i++) {
            if (numWays[i] > 1) {
                return {};
            }
            if (numWays[i] == 0) {
                continue;
            }
            ans.push_back(i);
            for (int j = n; j >= i; j--) {
                numWays[j] -= numWays[j - i];
                if (numWays[j] < 0) {
                    return {};
                }
            }
        }
        return ans;
    }
};