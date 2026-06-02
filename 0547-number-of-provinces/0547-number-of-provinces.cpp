class Solution {
public:
    void dfs(int node, vector<int> adjL[], vector<bool>& vis) {
        vis[node] = true;
        for (int& adjNode : adjL[node]) {
            if (!vis[adjNode]) {
                dfs(adjNode, adjL, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adjL[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] && i != j) {
                    adjL[i].push_back(j);
                }
            }
        }
        int no_of_pro = 0;
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                no_of_pro++;
                dfs(i, adjL, vis);
            }
        }
        return no_of_pro;
    }
};