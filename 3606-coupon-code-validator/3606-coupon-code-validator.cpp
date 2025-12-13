class Solution {
public:
    bool static cmp(pair<string, string>& a, pair<string, string>& b) {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second < b.second;
    }
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {

        int n = code.size();
        vector<pair<string, string>> v;
        for (int i = 0; i < n; i++) {
            bool t1 = true, t2 = true, t3 = true;
            if (code[i].empty()) {
                t1 = false;
            } else {
                for (int j = 0; j < code[i].size(); j++) {
                    char ch = code[i][j];
                    if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' ||
                        ch >= '0' && ch <= '9' || ch == '_') {
                        continue;
                    } else {
                        t1 = false;
                        break;
                    }
                }
            }

            if (businessLine[i] != "electronics" &&
                businessLine[i] != "grocery" && businessLine[i] != "pharmacy" &&
                businessLine[i] != "restaurant") {
                    
                t2 = false;
            }
            if (isActive[i] == false) {
                t3 = false;
            }

            if (t1 && t2 && t3) {
                v.push_back({code[i], businessLine[i]});
            }
        }

        sort(v.begin(), v.end(), cmp);
        vector<string> ans;
        for (auto it : v) {
            ans.push_back(it.first);
        }
        return ans;
    }
};