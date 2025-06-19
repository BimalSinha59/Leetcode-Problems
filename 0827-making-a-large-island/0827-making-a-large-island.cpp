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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 0)
                    continue;
                for (int i = 0; i < 4; i++) {
                    int newr = r + dr[i];
                    int newc = c + dc[i];
                    if (newr >= 0 && newr < n && newc >= 0 && newc < n &&
                        grid[newr][newc] == 1) {
                        int nodeNo = r * n + c;
                        int adjNNo = newr * n + newc;
                        ds.unionBySize(nodeNo, adjNNo);
                    }
                }
            }
        }
        int largestIld = 0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1)
                    continue;
                set<int> components;
                for (int i = 0; i < 4; i++) {
                    int newr = r + dr[i];
                    int newc = c + dc[i];
                    if (newr >= 0 && newr < n && newc >= 0 && newc < n &&
                        grid[newr][newc] == 1) {
                        components.insert(ds.findUPar(newr * n + newc));
                    }
                }
                int sizeTotal = 0;
                for (auto it : components) {
                    sizeTotal += ds.size[it];
                }
                largestIld = max(largestIld, sizeTotal + 1);
            }
        }
        for (int cellNo = 0; cellNo < n * n; cellNo++) {
            largestIld = max(largestIld, ds.size[ds.findUPar(cellNo)]);
        }
        return largestIld;
    }
};