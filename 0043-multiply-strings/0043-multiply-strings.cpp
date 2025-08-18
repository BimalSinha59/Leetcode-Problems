class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();
        string a, b;
        if (n <= m) {
            b = num2;
            a = num1;
        } else {
            b = num1;
            a = num2;
        }
        int mini = min(n, m);
        int maxi = max(n, m);
        vector<string> v(mini, string(m + n + 1, '0'));
        for (int i = mini - 1; i >= 0; i--) {
            int carry = 0;
            int k = maxi + i + 1;
            for (int j = maxi - 1; j >= 0; j--) {
                int x = a[i] - '0';
                int y = b[j] - '0';
                int mul = x * y + carry;
                int ans = mul % 10;
                carry = mul / 10;
                v[mini - i - 1][k] = ans + '0';
                k--;
            }
            v[mini - i - 1][k] = carry + '0';
        }
        string ans;
        int carry = 0;
        for (int i = m + n; i >= 0; i--) {
            int sum = 0;
            for (int j = 0; j < mini; j++) {
                sum += (v[j][i] - '0');
            }
            sum += carry;
            int dig = sum % 10;
            carry = sum / 10;
            ans.push_back(dig + '0');
        }
        while (!ans.empty() && ans.back() == '0') {
            ans.pop_back();
        }
        if (ans.empty()) {
            return "0";
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};