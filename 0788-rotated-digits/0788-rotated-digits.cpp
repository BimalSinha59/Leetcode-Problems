class Solution {
public:
    int rotatedDigits(int n) {
        int ans = 0;
        unordered_map<int, int> mp;
        mp[0] = 0, mp[1] = 1, mp[8] = 8;
        mp[2] = 5, mp[5] = 2;
        mp[6] = 9, mp[9] = 6;
        for (int i = 0; i <= n; i++) {
            string str;
            int num = i;
            while (num > 0) {
                int dig = num % 10;
                if (dig == 3 || dig == 4 || dig == 7) {
                    str = "";
                    break;
                }
                str.push_back(mp[dig] + '0');
                num /= 10;
            }
            if (str.size()) {
                reverse(str.begin(), str.end());
                int nnum = stoi(str);
                if (nnum != i) {
                    ans++;
                }
            }
        }
        return ans;
    }
};