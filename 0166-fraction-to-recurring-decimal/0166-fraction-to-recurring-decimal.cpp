class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";
        }
        string ans;
        if ((numerator < 0) ^ (denominator < 0)) {
            ans.push_back('-');
        }
        long long ddend = abs(1LL * numerator);
        long long dsor = abs(1LL * denominator);
        long long intPart = ddend / dsor;
        ans += to_string(intPart);
        long long remdr = ddend % dsor;
        if (remdr == 0) {
            return ans;
        }
        ans.push_back('.');
        unordered_map<long long, int> mp;
        while (remdr != 0) {
            if (mp.count(remdr)) {
                ans.insert(mp[remdr], "(");
                ans.push_back(')');
                break;
            }
            mp[remdr] = ans.size();
            remdr *= 10;
            ans += to_string(remdr / dsor);
            remdr %= dsor;
        }
        return ans;
    }
};