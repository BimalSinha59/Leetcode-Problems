class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {

        int n=routes.size();
        if(source==target){
            return 0;
        }
        
        unordered_map<int,vector<int>>adj;
        for(int i=0; i<n; i++){
            for(auto it:routes[i]){
                adj[it].push_back(i);
            }
        }

        queue<int> q;
        unordered_set<int> vis;
        for(auto it:adj[source]){
            q.push(it);
            vis.insert(it);
        }
        int ans=1;
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                int node=q.front();
                q.pop();

                for(auto it:routes[node]){
                    if(it==target){
                        return ans;
                    }

                    for(auto adjNode:adj[it]){
                        if(vis.find(adjNode)==vis.end()){
                            vis.insert(adjNode);
                            q.push(adjNode);
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};