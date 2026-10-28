class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, 0);
        int provinces = 0;

        for (int start = 0; start < n; start++) {
            if (visited[start] == 1) {
                continue;
            }

            provinces++;

            queue<int> q;

            visited[start] = 1;

            q.push(start);

            while (!q.empty()) {
                int city = q.front();
                q.pop();

                for (int nextCity = 0; nextCity < n; nextCity++) {
                    if (isConnected[city][nextCity] == 1 &&
                        visited[nextCity] == 0) {
                        visited[nextCity] = 1;
                        q.push(nextCity);
                    }
                }
            }
        }

        return provinces;
    }
};