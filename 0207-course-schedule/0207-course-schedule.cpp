class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adjL[numCourses];
        vector<int> in_degree(numCourses, 0);
        for (auto& prerequisite : prerequisites) {
            int a = prerequisite[0];
            int b = prerequisite[1];
            adjL[b].push_back(a);
            in_degree[a]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }
        int cnt = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;
            for (int& adjNode : adjL[node]) {
                in_degree[adjNode]--;
                if (in_degree[adjNode] == 0) {
                    q.push(adjNode);
                }
            }
        }
        if (cnt == numCourses) {
            return true;
        }
        return false;
    }
};