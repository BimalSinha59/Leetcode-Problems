class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 1;
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> mp;
            for (int j = i; j < n; j++) {
                mp[s[j]]++;
                int mini = 1e9, maxi = -1e9;
                for (auto it : mp) {
                    mini = min(mini, it.second);
                    maxi = max(maxi, it.second);
                }
                if (mini == maxi) {
                    ans = max(ans, (int)mp.size() * mini);
                }
            }
        }
        return ans;
    }
};