class Solution {
public:
    unordered_map<string, bool> dp;
    bool backTrack(string bm, unordered_map<string, vector<char>>& mp,
                   string str, int idx) {

        if (bm.size() == 1) {
            return true;
        }
        if (str.size() == bm.size() - 1) {
            if (dp.count(str)) {
                return dp[str];
            }
            return dp[str] = backTrack(str, mp, "", 0);
        }
        string ky = bm.substr(idx, 2);
        if (mp.find(ky) == mp.end()) {
            return false;
        }
        for (auto ch : mp[ky]) {
            str.push_back(ch);
            if (backTrack(bm, mp, str, idx + 1)) {
                return true;
            }
            str.pop_back();
        }
        return false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> mp;
        for (auto& it : allowed) {
            string str = it.substr(0, 2);
            mp[str].push_back(it[2]);
        }
        return backTrack(bottom, mp, "", 0);
    }
};