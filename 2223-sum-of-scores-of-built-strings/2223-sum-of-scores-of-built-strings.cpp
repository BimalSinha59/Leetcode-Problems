class Solution {
public:
    vector<int> getZArray(const string& str) {
        int n = str.size();
        vector<int> Z(n, 0);
        int L = 0, R = 0;
        for (int i = 1; i < n; i++) {
            if (i <= R) {
                Z[i] = min(R - i + 1, Z[i - L]);
            }
            while (i + Z[i] < n && str[Z[i]] == str[i + Z[i]]) {
                Z[i]++;
            }
            if (i + Z[i] - 1 > R) {
                L = i;
                R = i + Z[i] - 1;
            }
        }
        return Z;
    }
    long long sumScores(string s) {
        int n = s.size();
        vector<int> zrr = getZArray(s);
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans = 1LL * (ans + zrr[i]);
        }
        return 1LL * (ans + n);
    }
};