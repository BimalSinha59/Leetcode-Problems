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
        if (node == parent[node]){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v){
            return;
        }
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
                if (grid[r][c] == 0){
                    continue;
                }
                for (int i = 0; i < 4; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                        grid[nr][nc] == 1) {
                        int nodeNo = r * n + c;
                        int adjNNo = nr * n + nc;
                        ds.unionBySize(nodeNo, adjNNo);
                    }
                }
            }
        }
        int largest_island = 0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1)
                    continue;
                set<int> components;
                for (int i = 0; i < 4; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                        grid[nr][nc] == 1) {
                        components.insert(ds.findUPar(nr * n + nc));
                    }
                }
                int sizeTotal = 0;
                for (auto it : components) {
                    sizeTotal += ds.size[it];
                }
                largest_island = max(largest_island, sizeTotal + 1);
            }
        }
        for (int cellNo = 0; cellNo < n * n; cellNo++) {
            largest_island = max(largest_island, ds.size[ds.findUPar(cellNo)]);
        }
        return largest_island;
    }
};