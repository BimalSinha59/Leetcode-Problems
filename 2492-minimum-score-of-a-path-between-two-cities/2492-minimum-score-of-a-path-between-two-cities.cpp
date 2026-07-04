class DisjointSet {
public:
    vector<int> parent;
    vector<int> size;
    DisjointSet(int n) {
        parent.resize(n + 1);
        parent.resize(n + 1, 1);
        for (int i = 1; i <= n; i++) {
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
        if (upar_u > upar_v) {
            parent[upar_v] = upar_u;
        } else {
            parent[upar_u] = upar_v;
        }
    }
};

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        DisjointSet ds(n);
        for (auto& it : roads) {
            int u = it[0];
            int v = it[1];
            ds.unionBySize(u, v);
        }
        unordered_set<int> unconnectedNodes;
        for (int i = 1; i <= n; i++) {
            if (ds.findUpar(1) != ds.findUpar(i)) {
                unconnectedNodes.insert(i);
            }
        }
        int minScore = 1e9;
        for (auto& it : roads) {
            int u = it[0], v = it[1], w = it[2];
            if (!unconnectedNodes.count(u) && !unconnectedNodes.count(v)) {
                minScore = min(minScore, w);
            }
        }
        return minScore;
    }
};