class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> last_pos(3, -1);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            last_pos[s[i] - 'a'] = i;
            ans += 1 + min({last_pos[0], last_pos[1], last_pos[2]});
        }
        return ans;
    }
};