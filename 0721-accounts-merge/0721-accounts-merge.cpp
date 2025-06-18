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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        unordered_map<string,int>mapMailNode;
        DisjointSet ds(n);
        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                string mail=accounts[i][j];
                if(mapMailNode.find(mail)==mapMailNode.end()){
                    mapMailNode[mail]=i;
                }
                else{
                    ds.unionBySize(i,mapMailNode[mail]);
                }
            }
        }
        vector<string> mails[n];
        for(auto it:mapMailNode){
            string mail = it.first;
            int node = ds.findUPar(it.second);
            mails[node].push_back(mail);
        }
        
        vector<vector<string>>ans;
        for(int i=0; i<n; i++){
            if(mails[i].size()==0) continue;
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            sort(mails[i].begin(),mails[i].end());
            for(auto it:mails[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};