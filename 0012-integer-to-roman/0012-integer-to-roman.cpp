class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, string> mp;
        mp[1] = "I";
        mp[5] = "V";
        mp[10] = "X";
        mp[50] = "L";
        mp[100] = "C";
        mp[500] = "D";
        mp[1000] = "M";
        mp[4] = "IV";
        mp[9] = "IX";
        mp[40] = "XL";
        mp[90] = "XC";
        mp[400] = "CD";
        mp[900] = "CM";
        string ans;
        string s = to_string(num);
        int n = s.size();
        int m = n - 1;
        for (int i = 0; i < n; i++) {
            int x = s[i] - '0';
            int y = 1;
            int mm = m;
            while (mm--) {
                y *= 10;
            }
            y *= x;
            if (mp.find(y) != mp.end()) {
                ans += mp[y];
            } else {
                if (x < 4) {
                    int xx = x;
                    while (xx--) {
                        ans += mp[y / x];
                    }
                } else {
                    int xx = x - 5;
                    int yy = y / x;
                    ans += mp[5 * yy];
                    while (xx--) {
                        ans += mp[yy];
                    }
                }
            }
            m--;
        }
        return ans;
    }
};