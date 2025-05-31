class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        int n=prerequisites.size();
        for(int i=0; i<n; i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int>inDegree(numCourses,0);
        for(int i=0; i<numCourses; i++){
            for(auto it:adj[i]){
                inDegree[it]++; 
            }
        }
        queue<int>q;
        for(int i=0; i<numCourses; i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        int cnt=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            cnt++;
            for(auto it:adj[node]){
                inDegree[it]--;
                if(inDegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(cnt==numCourses){
            return true;
        }
        return false;
        
    }
};