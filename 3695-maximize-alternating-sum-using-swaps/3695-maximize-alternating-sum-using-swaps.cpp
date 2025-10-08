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
    long long maxAlternatingSum(vector<int>& nums, vector<vector<int>>& swaps) {
        int n=nums.size();
        DisjointSet ds(n);
        for(auto it:swaps){
            ds.unionBySize(it[0],it[1]);
        }
        vector<vector<pair<int,int>>>v(n);
        for(int i=0; i<n; i++){
            int up=ds.findUPar(i);
            v[up].push_back({nums[i],i});
        }
        long long ans=0;
        for(auto it:v){
            long long sum=0;
            int es=0;
            for(int i=0; i<it.size(); i++){
                sum+=it[i].first;
                if(it[i].second%2==0){
                    es++;
                }
            }
            sort(it.rbegin(),it.rend());
            long long esum=0;
            for(int i=0; i<es; i++){
                esum+=it[i].first;
            }
            ans+=(esum-(sum-esum));
        }
        return ans;
    }
};