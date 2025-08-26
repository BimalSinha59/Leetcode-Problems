class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for (int k = 1; k < n; k++) {
            string temp;
            int i = 0, j = 0;
            while (i < ans.size()) {
                int cnt = 0;
                while (ans[i] == ans[j]) {
                    j++;
                }
                cnt = j - i;
                char ch = cnt + '0';
                temp.push_back(ch);
                temp.push_back(ans[i]);
                i = j;
            }
            ans = temp;
        }
        return ans;
    }
};