class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
        }
        vector<vector<int>> dist(n, vector<int>(k + 1, 1e9));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>>pq;
        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, node, cnt] = pq.top();
            pq.pop();

            if (node == n - 1) {
                return d;
            }

            if (d > dist[node][cnt]) {
                continue;
            }

            for (auto& edge : adj[node]) {
                int next_node = edge.first;
                int weight = edge.second;

                int next_cnt = (labels[next_node] == labels[node]) ? cnt + 1 : 1;

                if (next_cnt <= k) {
                    if (d + weight < dist[next_node][next_cnt]) {
                        dist[next_node][next_cnt] = d + weight;
                        pq.push({dist[next_node][next_cnt], next_node, next_cnt});
                    }
                }
            }
        }

        return -1;
    }
};