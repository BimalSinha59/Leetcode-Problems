class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int carry = 0;
        int n = a.size(), m = b.size();
        int i = n - 1, j = m - 1;
        while (i >= 0 && j >= 0) {
            int sum = (a[i] - '0') + (b[j] - '0') + carry;
            int dig = sum % 2;
            ans.push_back(dig + '0');
            carry = sum / 2;
            i--;
            j--;
        }
        while (i >= 0) {
            int sum = (a[i] - '0') + carry;
            int dig = sum % 2;
            ans.push_back(dig + '0');
            carry = sum / 2;
            i--;
        }
        while (j >= 0) {
            int sum = (b[j] - '0') + carry;
            int dig = sum % 2;
            ans.push_back(dig + '0');
            carry = sum / 2;
            j--;
        }
        if (carry) {
            ans.push_back(carry + '0');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};