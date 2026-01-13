class Solution {
public:
    vector<string> ans;
    int n;
    bool isValid(string str) {
        if (str[0] == '0') {
            return false;
        }
        int value = stoi(str);
        return value <= 255;
    }
    void createIP(int idx, int part, string curr, string& s) {
        if (idx == n && part == 4) {
            curr.pop_back();
            ans.push_back(curr);
            return;
        }
        if (idx + 1 <= n) {
            createIP(idx + 1, part + 1, curr + s.substr(idx, 1) + ".", s);
        }
        if (idx + 2 <= n && isValid(s.substr(idx, 2))) {
            createIP(idx + 2, part + 1, curr + s.substr(idx, 2) + ".", s);
        }
        if (idx + 3 <= n && isValid(s.substr(idx, 3))) {
            createIP(idx + 3, part + 1, curr + s.substr(idx, 3) + ".", s);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        n = s.size();
        if (n < 4 || n > 12) {
            return {};
        }
        string curr = "";
        createIP(0, 0, curr, s);
        return ans;
    }
};