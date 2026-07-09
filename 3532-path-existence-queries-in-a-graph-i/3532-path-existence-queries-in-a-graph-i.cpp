class DisjointSet {
public:
    vector<int> size, parent;
    DisjointSet(int n) {
        size.resize(n);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            size[i] = 1;
            parent[i] = i;
        }
    }

    int findUpar(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findUpar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int upar_u = findUpar(u);
        int upar_v = findUpar(v);
        if (upar_u == upar_v) {
            return;
        }
        if (size[upar_u] < size[upar_v]) {
            parent[upar_u] = upar_v;
            size[upar_v] += size[upar_u];
        } else {
            parent[upar_v] = upar_u;
            size[upar_u] += size[upar_v];
        }
    }
};
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        DisjointSet ds(n);
        for (int i = 1; i < n; i++) {
            int u = i - 1, v = i;
            if (nums[v] - nums[u] <= maxDiff) {
                ds.unionBySize(u, v);
            }
        }
        vector<bool> ans;
        for (const auto& q : queries) {
            int u = q[0], v = q[1];
            if (ds.findUpar(u) == ds.findUpar(v)) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }
        return ans;
    }
};