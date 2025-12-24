class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int asum = 0;
        for (int& app : apple) {
            asum += app;
        }
        sort(capacity.rbegin(), capacity.rend());
        int ans = 0;
        int cs = 0;
        for (int& cap : capacity) {
            ans++;
            cs += cap;
            if (cs >= asum) {
                break;
            }
        }
        return ans;
    }
};