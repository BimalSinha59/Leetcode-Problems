class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        int mxf = 0;
        for (char& ch : tasks) {
            mp[ch]++;
            mxf = max(mxf, mp[ch]);
        }
        int m = tasks.size();
        int ans = (mxf - 1) * (n + 1);
        for (auto& it : mp) {
            if (it.second == mxf) {
                ans++;
            }
        }
        ans = max(ans, m);
        return ans;
    }
};