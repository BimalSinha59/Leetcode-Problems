class Solution {
public:
    bool isPossible(int &mid, int &n, long long &k, vector<vector<pair<int, int>>>& adj){
        vector<long long>dis(n,LLONG_MAX);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>>pq;
        dis[0]=0;
        pq.push({0,0});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            long long dst=it.first;
            int u=it.second;
            if(dst>k){
                return false;
            }
            if(u==n-1){
                return true;
            }
            if(dst>dis[u]){
                continue;
            }
            for(auto &it:adj[u]){
                int v=it.first;
                int w=it.second;
                if(w<mid){
                    continue;
                }
                if(dis[v]>dis[u]+w){
                    dis[v]=dis[u]+w;
                    pq.push({dis[v],v});
                }
            }
        }
        return false;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n=online.size();
        vector<vector<pair<int, int>>>adj(n);
        int low=INT_MAX,high=0;
        for(auto &e:edges){
            int u=e[0],v=e[1],w=e[2];
            if(!online[u] || !online[v]){
                continue;
            }
            adj[u].push_back({v,w});
            low=min(low,w);
            high=max(high,w);
        }
        if(!isPossible(low,n,k,adj)){
            return -1;
        }
        int ans;
        while(low<=high){
            int mid=(low+high)>>1;
            if(isPossible(mid,n,k,adj)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};