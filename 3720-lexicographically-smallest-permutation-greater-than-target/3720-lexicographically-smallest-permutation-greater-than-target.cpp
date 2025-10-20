class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        multiset<char> mst;
        for (auto ch : s) {
            mst.insert(ch);
        }
        vector<string> ans;
        string pref = "";
        for (int i = 0; i < n; i++) {
            auto ge = mst.upper_bound(target[i]);
            if (ge != mst.end()) {
                char ch = *ge;
                string temp = pref;
                temp.push_back(ch);
                mst.erase(ge);
                for (char it : mst) {
                    temp.push_back(it);
                }
                mst.insert(ch);
                ans.push_back(temp);
            }
            auto nxt = mst.find(target[i]);
            if (nxt == mst.end()) {
                break;
            }
            pref.push_back(*nxt);
            mst.erase(nxt);
        }
        if (ans.size() == 0) {
            return "";
        }
        return *min_element(ans.begin(), ans.end());
    }
};