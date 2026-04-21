class DisjointSet {

public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target,
                               vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        DisjointSet ds(n);
        for (auto v : allowedSwaps) {
            ds.unionBySize(v[0], v[1]);
        }
        unordered_map<int, unordered_map<int, int>> mp;
        for (int i = 0; i < n; i++) {
            int idx = ds.findUPar(i);
            mp[idx][source[i]]++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int idx = ds.findUPar(i);
            if (mp[idx][target[i]] > 0) {
                mp[idx][target[i]]--;
            } else {
                ans++;
            }
        }
        return ans;
    }
};