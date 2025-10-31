class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) {
            return "";
        }
        int rnine = sum / 9;
        string ans(rnine, '9');
        int remd = sum - rnine * 9;
        if (remd != 0) {
            ans.push_back(remd + '0');
        }
        if (ans.size() < num) {
            string temp(num - ans.size(), '0');
            ans += temp;
        }
        return ans;
    }
};