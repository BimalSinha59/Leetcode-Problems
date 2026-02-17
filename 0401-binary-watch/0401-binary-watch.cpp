class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 60; j++) {
                int bitsh = __builtin_popcount(i);
                int bitsm = __builtin_popcount(j);
                if (bitsh + bitsm == turnedOn) {
                    string str = to_string(i);
                    str.push_back(':');
                    if (j < 10) {
                        str.push_back('0');
                    }
                    str += to_string(j);
                    ans.push_back(str);
                }
            }
        }
        return ans;
    }
};