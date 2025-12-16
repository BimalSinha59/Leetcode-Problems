class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int m = target.size();
        int i = 0;
        vector<string> ans;
        int istm = 1;
        while (i < m) {
            if (target[i] == istm) {
                ans.push_back("Push");
                i++;
                istm++;
            } else {
                ans.push_back("Push");
                ans.push_back("Pop");
                istm++;
            }
        }
        return ans;
    }
};