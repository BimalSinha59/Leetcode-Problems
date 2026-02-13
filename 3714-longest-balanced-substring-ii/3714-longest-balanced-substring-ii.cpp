class Solution {
public:
    int singleChar(string& s, int n) {
        int maxi = 0;
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                cnt++;
                maxi = max(maxi, cnt);
            } else {
                cnt = 1;
            }
        }
        maxi = max(maxi, cnt);
        return maxi;
    }
    int doubleChar(string& s, int n, char c1, char c2) {
        map<int, int> mp;
        mp[0] = -1;
        int ans = 0;
        int df = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != c1 && s[i] != c2) {
                mp.clear();
                mp[0] = i;
                df = 0;
                continue;
            }
            if (s[i] == c1) {
                df++;
            } else {
                df--;
            }
            if (mp.find(df) != mp.end()) {
                ans = max(ans, i - mp[df]);
            } else {
                mp[df] = i;
            }
        }
        return ans;
    }
    int tripleChar(string& s, int n) {
        int cnta = 0, cntb = 0, cntc = 0;
        map<pair<int, int>, int> mp;
        mp[{0, 0}] = -1;
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') {
                cnta++;
            } else if (s[i] == 'b') {
                cntb++;
            } else {
                cntc++;
            }
            if (mp.find({cntb - cnta, cntc - cnta}) != mp.end()) {
                maxi = max(maxi, i - mp[{cntb - cnta, cntc - cnta}]);
            } else {
                mp[{cntb - cnta, cntc - cnta}] = i;
            }
        }
        return maxi;
    }
    int longestBalanced(string s) {
        int n = s.size();
        int ans1 = singleChar(s, n);
        int ans21 = doubleChar(s, n, 'a', 'b');
        int ans22 = doubleChar(s, n, 'a', 'c');
        int ans23 = doubleChar(s, n, 'b', 'c');
        int ans3 = tripleChar(s, n);
        return max({ans1, ans21, ans22, ans23, ans3});
    }
};