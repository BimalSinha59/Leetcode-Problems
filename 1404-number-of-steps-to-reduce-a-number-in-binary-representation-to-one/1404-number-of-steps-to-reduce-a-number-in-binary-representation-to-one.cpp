class Solution {
public:
    int numSteps(string s) {
        int n = s.size();
        int ans = 0;
        while (s.size() > 1) {
            if (s.back() == '0') {
                s.pop_back();
            } else {
                int carry = 1;
                string str;
                for (int i = s.size() - 1; i >= 0; i--) {
                    int dig = s[i] - '0';
                    int add = dig + carry;
                    int ndig = add % 2;
                    carry = add / 2;
                    str.push_back(ndig + '0');
                }
                if (carry) {
                    str.push_back('1');
                }
                reverse(str.begin(), str.end());
                s = str;
            }
            ans++;
        }
        return ans;
    }
};