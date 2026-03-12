class DisjointSet {
    vector<int> parent, size;

public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
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
        } else if (upar_u < upar_v) {
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
    bool checkIfPossible(int n, vector<vector<int>>& edges, int k, int mid) {
        DisjointSet ds(n);
        vector<pair<int, int>> cbuEdges;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int s = edge[2];
            int must = edge[3];
            if (must == 1) {
                if (s < mid) {
                    return false;
                }
                ds.unionBySize(u, v);
            } else {
                if (s >= mid) {
                    ds.unionBySize(u, v);
                } else {
                    if (2 * s >= mid) {
                        cbuEdges.push_back({u, v});
                    }
                }
            }
        }
        for (auto& it : cbuEdges) {
            int u = it.first;
            int v = it.second;
            if (ds.findUpar(u) != ds.findUpar(v) && k) {
                ds.unionBySize(u, v);
                k--;
            }
        }
        int root = ds.findUpar(0);
        for (int i = 1; i < n; i++) {
            if (ds.findUpar(i) != root) {
                return false;
            }
        }
        return true;
    }
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        DisjointSet ds(n);
        int low = 1e9, high = -1e9;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int s = edge[2];
            int must = edge[3];
            if (must == 1) {
                if (ds.findUpar(u) == ds.findUpar(v)) {
                    return -1;
                }
                ds.unionBySize(u, v);
            }
            low = min(low, s);
            high = max(high, s);
            if (must == 0) {
                high = max(high, 2 * s);
            }
        }
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (checkIfPossible(n, edges, k, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};