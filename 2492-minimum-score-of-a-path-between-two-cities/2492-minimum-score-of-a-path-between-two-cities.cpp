class DisjointSet {
public:
    vector<int> parent;
    vector<int> size;
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            size[i]=1;
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
        if(upar_u==upar_v){
            return;
        }
        if (size[upar_u] > size[upar_v]) {
            parent[upar_v] = upar_u;
            size[upar_u]+=size[upar_v];
        } else {
            parent[upar_u] = upar_v;
            size[upar_v]+=size[upar_u];
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