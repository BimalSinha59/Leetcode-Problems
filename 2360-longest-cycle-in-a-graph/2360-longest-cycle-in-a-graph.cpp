class Solution {
public:
    bool dfsCheck(int node, vector<int>& edges, vector<int>& vis,int &ans,vector<int>& v) {
        vis[node] = 1;
        v.push_back(node);
        int it = edges[node];
        if(it!=-1){
            if (vis[it] == 0) {
                if (dfsCheck(it, edges, vis,ans,v)) {
                    return true;
                }
            } 
            else if (vis[it] == 1) {
                int c=0;
                for(int i=v.size()-1; i>=0; i--){
                    c++;
                    vis[v[i]]=2;
                    if(v[i]==it){
                        break;
                    }
                }
                ans=c;
                return true;
            }
        }
        vis[node] = 2;
        return false;
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> vis(n, 0);
        int res=-1;
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                vector<int>v;
                int ans=0;
                if(dfsCheck(i, edges, vis, ans,v)){
                    res=max(res,ans);
                }
            }
        }
        return res;
    }
};