class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(0);
        vis[0] = true;
        int steps = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int idx = q.front();
                if (idx == n - 1) {
                    return steps;
                }
                q.pop();
                vis[idx] = true;
                if (idx + 1 < n && !vis[idx + 1]) {
                    q.push(idx + 1);
                }
                if (idx - 1 >= 0 && !vis[idx - 1]) {
                    q.push(idx - 1);
                }
                if (mp[arr[idx]].size()) {
                    for (int& i : mp[arr[idx]]) {
                        if (!vis[i]) {
                            q.push(i);
                        }
                    }
                }
                mp.erase(arr[idx]);
            }
            steps++;
        }
        return -1;
    }
};