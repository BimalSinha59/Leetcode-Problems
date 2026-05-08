const int MX = 1000001;
vector<int> facts[MX];
bool initialized = []() {
    for (int i = 2; i < MX; ++i) {
        if (facts[i].empty()) {
            for (int j = i; j < MX; j += i) {
                facts[j].push_back(i);
            }
        }
    }
    return true;
}();

class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            for (int& p : facts[nums[i]]) {
                mp[p].push_back(i);
            }
        }
        queue<int> q;
        vector<bool> vis(n, false);
        q.push(0);
        vis[0] = true;
        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int i = q.front();
                if (i == n - 1) {
                    return steps;
                }
                q.pop();
                if (i - 1 >= 0 && !vis[i - 1]) {
                    q.push(i - 1);
                    vis[i - 1] = true;
                }
                if (i + 1 < n && !vis[i + 1]) {
                    q.push(i + 1);
                    vis[i + 1] = true;
                }
                if (facts[nums[i]].size() == 1) {
                    int p = nums[i];
                    if (mp.count(p)) {
                        for (int& idx : mp[p]) {
                            if (!vis[idx]) {
                                q.push(idx);
                                vis[idx] = true;
                            }
                        }
                        mp[p].clear();
                    }
                }
            }
            steps++;
        }
        return steps;
    }
};