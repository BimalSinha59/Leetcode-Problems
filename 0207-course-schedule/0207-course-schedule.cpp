class Solution {
public:
    bool dfs_cycle_check(int node, vector<int> adjL[], vector<int>& vis, vector<int>& pathVis) {
        vis[node] = 1;
        pathVis[node] = 1;
        for (int& adjNode : adjL[node]) {
            if (!vis[adjNode]) {
                if (dfs_cycle_check(adjNode, adjL, vis, pathVis)) {
                    return true;
                }
            } else if (pathVis[adjNode]) {
                return true;
            }
        }
        pathVis[node] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adjL[numCourses];
        for (auto& prerequisite : prerequisites) {
            int a = prerequisite[0];
            int b = prerequisite[1];
            adjL[b].push_back(a);
        }
        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs_cycle_check(i, adjL, vis, pathVis)) {
                    return false;
                }
            }
        }
        return true;
    }
};