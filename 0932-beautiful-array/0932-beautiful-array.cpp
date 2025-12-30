class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> ans;
        ans.push_back(1);
        while (ans.size() < n) {
            vector<int> temp;
            for (int& num : ans) {
                if (2 * num - 1 <= n) {
                    temp.push_back(2 * num - 1);
                }
            }
            for (int& num : ans) {
                if (2 * num <= n) {
                    temp.push_back(2 * num);
                }
            }
            ans = temp;
        }
        return ans;
    }
};