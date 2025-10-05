class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string str = a;
        int ans = 1;
        while (a.size() < b.size()) {
            a += str;
            ans++;
        }
        if (a.find(b) != string::npos) {
            return ans;
        }
        a += str;
        ans++;
        if (a.find(b) != string::npos) {
            return ans;
        }
        return -1;
    }
};
