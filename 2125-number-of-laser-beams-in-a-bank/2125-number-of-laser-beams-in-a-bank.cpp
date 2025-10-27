class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        int prvs = 0;
        for (auto it : bank) {
            int curr = 0;
            for (auto ch : it) {
                if (ch == '1') {
                    curr++;
                }
            }
            ans += prvs * curr;
            if (curr != 0) {
                prvs = curr;
            }
        }
        return ans;
    }
};