class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, int temp) {
        vis[node] = temp;
        for (auto it : adj[node]) {
            if (vis[it] == -1) {
                dfs(it, adj, vis, temp);
            }
        }
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections,
                               vector<vector<int>>& queries) {

        vector<vector<int>> adj(c + 1);
        for (int i = 0; i < connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(c + 1, -1);
        int temp = 0;
        for (int i = 1; i <= c; i++) {
            if (vis[i] == -1) {
                dfs(i, adj, vis, temp);
                temp++;
            }
        }

        vector<set<int>> v(temp);
        for (int i = 1; i <= c; i++) {
            v[vis[i]].insert(i);
        }

        vector<int> ans;
        for (int i = 0; i < queries.size(); i++) {
            int node = queries[i][1];
            int ot = queries[i][0];
            if (ot == 1) {
                if (v[vis[node]].find(node) != v[vis[node]].end()) {
                    ans.push_back(node);
                } 
                else if (v[vis[node]].size() == 0) {
                    ans.push_back(-1);
                } 
                else {
                    ans.push_back(*v[vis[node]].begin());
                }
            }
            else {
                if (v[vis[node]].find(node) != v[vis[node]].end()) {
                    v[vis[node]].erase(node);
                }
            }
        }
        return ans;
    }
};