class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries,
                                vector<string>& dictionary) {
        vector<string> ans;
        for (string& str : queries) {
            for (string& dicStr : dictionary) {
                int cnt = 0;
                for (int i = 0; i < dicStr.size(); i++) {
                    if (str[i] != dicStr[i]) {
                        cnt++;
                    }
                }
                if (cnt <= 2) {
                    ans.push_back(str);
                    break;
                }
            }
        }
        return ans;
    }
};