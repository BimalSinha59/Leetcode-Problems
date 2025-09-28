class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> ans;
        long long mul = 1;
        int num = n;
        while (num > 0) {
            int dig = num % 10;
            int res = dig * mul;
            if (res != 0) {
                ans.push_back(res);
            }
            num /= 10;
            mul *= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};