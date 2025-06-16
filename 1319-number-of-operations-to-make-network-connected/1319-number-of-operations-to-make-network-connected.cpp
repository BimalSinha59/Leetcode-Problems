class DisjointSet{

public:
    vector<int> parent, size;
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extCable=0;
        for(auto it:connections){
            if(ds.findUPar(it[0])==ds.findUPar(it[1])){
                extCable++;
            }
            ds.unionBySize(it[0],it[1]);
        }
        int ccompo=0;
        for(int i=0; i<n; i++){
            if(ds.parent[i]==i){
                ccompo++;
            }
        }
        if(extCable>=ccompo-1){
            return ccompo-1;
        }
        return -1;
    }
};