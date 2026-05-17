class Solution {
public:
    bool solve(vector<int>& arr, int n, int i, vector<bool>& vis) {
        if (i < 0 || i >= n || vis[i]) {
            return false;
        }
        if (arr[i] == 0) {
            return true;
        }
        vis[i] = true;
        bool ans1 = solve(arr, n, i + arr[i], vis);
        bool ans2 = solve(arr, n, i - arr[i], vis);
        return vis[i] = (ans1 | ans2);
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> vis(n, false);
        return solve(arr, n, start, vis);
    }
};