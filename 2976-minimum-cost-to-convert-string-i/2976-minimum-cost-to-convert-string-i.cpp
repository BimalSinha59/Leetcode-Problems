class Solution {
public:
    void floydWarshall(vector<vector<int>>& graph, int V) {
        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    if (graph[i][k] != 1e9 && graph[k][j] != 1e9 &&
                        graph[i][k] + graph[k][j] < graph[i][j]) {
                        graph[i][j] = graph[i][k] + graph[k][j];
                    }
                }
            }
        }
    }
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {

        int n = original.size();
        vector<vector<int>> graph(26, vector<int>(26, 1e9));
        for (int i = 0; i < n; i++) {
            if (cost[i] < graph[original[i] - 'a'][changed[i] - 'a']) {
                graph[original[i] - 'a'][changed[i] - 'a'] = cost[i];
            }
        }
        floydWarshall(graph, 26);
        long long ans = 0;
        int m = source.size();
        for (int i = 0; i < m; i++) {
            if (source[i] == target[i]) {
                continue;
            }
            int src = source[i] - 'a';
            int tgt = target[i] - 'a';
            int minDistance = graph[src][tgt];
            if (minDistance == 1e9) {
                return -1;
            }
            ans += minDistance;
        }
        return ans;
    }
};