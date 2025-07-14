class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int u) {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    bool unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return false;
        if (rank[pu] < rank[pv]) swap(pu, pv);
        parent[pv] = pu;
        if (rank[pu] == rank[pv]) rank[pu]++;
        return true;
    }
};

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges, int k) {
        
        sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        });

        
        DSU dsu(n);
        vector<int> mstWeights;

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            if (dsu.unite(u, v)) {
                mstWeights.push_back(w);
            }
        }

        
        int numToRemove = k - 1;
        if (numToRemove >= mstWeights.size())
            return 0;

        sort(mstWeights.begin(), mstWeights.end(), greater<int>()); 
        return mstWeights[numToRemove];
    }
};
