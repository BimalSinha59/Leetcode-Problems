class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        vector<int> dis(n, -1);
        for (int i = 0; i < n; i++) {
            if (mp.count(nums[i]) && mp[nums[i]].size() > 1) {
                vector<int> v = mp[nums[i]];
                int m = v.size();
                for (int j = 0; j < m; j++) {
                    if (j == 0) {
                        dis[v[j]] = min(v[j] + n - v[m - 1], v[j + 1] - v[j]);
                    } else if (j == m - 1) {
                        dis[v[j]] = min(n - v[j] + v[0], v[j] - v[j - 1]);
                    } else {
                        dis[v[j]] = min(v[j] - v[j - 1], v[j + 1] - v[j]);
                    }
                }
                mp.erase(nums[i]);
            }
        }
        vector<int> ans;
        for (int& q : queries) {
            ans.push_back(dis[q]);
        }
        return ans;
    }
};