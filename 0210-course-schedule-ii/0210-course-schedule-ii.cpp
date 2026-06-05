class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adjL[numCourses];
        for (auto& prerequisite : prerequisites) {
            adjL[prerequisite[1]].push_back(prerequisite[0]);
        }
        vector<int> in_degree(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            for (int& adjNode : adjL[i]) {
                in_degree[adjNode]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> topo_order;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo_order.push_back(node);
            for (int& adjNode : adjL[node]) {
                in_degree[adjNode]--;
                if (in_degree[adjNode] == 0) {
                    q.push(adjNode);
                }
            }
        }
        if (topo_order.size() == numCourses) {
            return topo_order;
        }
        return {};
    }
};