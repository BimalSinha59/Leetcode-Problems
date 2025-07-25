class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n < 3) {
            vector<int> ans;
            for (int i = 0; i < n; ++i) {
                ans.push_back(i);
            }
            return ans;
        }

        vector<unordered_set<int>> adj(n);
        for (auto& edge : edges) {
            int a = edge[0], b = edge[1];
            adj[a].insert(b);
            adj[b].insert(a);
        }

        vector<int> leaves;
        for (int i = 0; i < n; ++i) {
            if (adj[i].size() == 1) {
                leaves.push_back(i);
            }
        }

        while (n > 2) {
            n -= leaves.size();
            vector<int> nleaves;
            for (int leaf : leaves) {
                int ngbr = *adj[leaf].begin();
                adj[ngbr].erase(leaf);
                if (adj[ngbr].size() == 1) {
                    nleaves.push_back(ngbr);
                }
            }
            leaves = nleaves;
        }

        return leaves;
    }
};
