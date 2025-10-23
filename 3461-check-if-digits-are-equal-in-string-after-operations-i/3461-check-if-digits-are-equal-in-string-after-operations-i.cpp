class Solution {
public:
    bool hasSameDigits(string s) {
        string str = s;
        while (str.size() > 2) {
            string temp;
            for (int i = 1; i < str.size(); i++) {
                int dig = ((str[i - 1] - '0') + (str[i] - '0')) % 10;
                temp.push_back(dig + '0');
            }
            str = temp;
        }
        return str[0] == str[1];
    }
};