class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        auto toLower = [](const string& s) {
            string t = s;
            for (char &c : t) c = tolower(c);
            return t;
        };
        auto maskVowels = [&](const string& s) {
            string t = s;
            for (char &c : t) {
                char lc = tolower(c);
                if (lc=='a' || lc=='e' || lc=='i' || lc=='o' || lc=='u')
                    c = '*';
                else
                    c = lc;
            }
            return t;
        };
        unordered_set<string> st(wordlist.begin(), wordlist.end());
        unordered_map<string,string> mp1;
        for (auto &w : wordlist) {
            string lw = toLower(w);
            if (!mp1.count(lw)) mp1[lw] = w;
        }
        unordered_map<string,string> mp2;
        for (auto &w : wordlist) {
            string mw = maskVowels(w);
            if (!mp2.count(mw)) mp2[mw] = w;
        }

        vector<string> ans;
        for (auto &q : queries) {
            if (st.count(q)) {
                ans.push_back(q);
                continue;
            }
            string lq = toLower(q);
            if (mp1.count(lq)) {
                ans.push_back(mp1[lq]);
                continue;
            }
            string mq = maskVowels(q);
            if (mp2.count(mq)) {
                ans.push_back(mp2[mq]);
                continue;
            }
            ans.push_back("");
        }
        return ans;
    }
};