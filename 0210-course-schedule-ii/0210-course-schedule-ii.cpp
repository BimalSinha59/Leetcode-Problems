class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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