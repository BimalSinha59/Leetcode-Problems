class Solution {
public:
    void dfs(int node,int para,vector<int> adj[],vector<int>& nums,vector<int>& stx,vector<unordered_set<int>>& des){
        stx[node]=nums[node];
        des[node].insert(node);
        for(auto child:adj[node]){
            if(child==para){
                continue;
            }
            dfs(child,node,adj,nums,stx,des);
            stx[node]=(stx[node]^stx[child]);
            des[node].insert(des[child].begin(),des[child].end());
        }
    }
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n=nums.size();
        vector<int> adj[n];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> stx(n);
        vector<unordered_set<int>> des(n,unordered_set<int>());
        dfs(0,-1,adj,nums,stx,des);
        int ans=1e9;
        int txr=stx[0];
        for(int i=1; i<n; i++){
            for(int j=i+1; j<n; j++){
                int ixr=stx[i];
                int jxr=stx[j];
                int part1,part2,part3;
                if(des[i].find(j)!=des[i].end()){
                    part1=jxr;
                    part2=ixr^jxr;
                    part3=txr^ixr;
                }
                else if(des[j].find(i)!=des[j].end()){
                    part1=ixr;
                    part2=jxr^ixr;
                    part3=txr^jxr;
                }
                else{
                    part1=ixr;
                    part2=jxr;
                    part3=txr^ixr^jxr;
                }
                int maxi=max(part1,max(part2,part3));
                int mini=min(part1,min(part2,part3));
                ans=min(ans,maxi-mini);
            }
        }
        return ans;
    }
};