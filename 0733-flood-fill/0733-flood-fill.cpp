class Solution {
public:
    void dfs(int sr, int sc, vector<vector<int>>& vis, int dr[], int dc[],
             int color, int iniColor, int n, int m) {
        vis[sr][sc] = color;

        for (int i = 0; i < 4; i++) {
            int nrow = sr + dr[i];
            int ncol = sc + dc[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                vis[nrow][ncol] == iniColor) {
                vis[nrow][ncol] = color;
                dfs(nrow,ncol,vis,dr,dc,color,iniColor,n,m);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis = image;
        vis[sr][sc] = color;
        int iniColor = image[sr][sc];
        if (iniColor == color) {
            return image;
        }

        //////BFS///////

        // queue<pair<int, int>> q;
        // q.push({sr, sc});
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        // while (!q.empty()) {
        //     int nr = q.front().first;
        //     int nc = q.front().second;
        //     q.pop();
        //     for (int i = 0; i < 4; i++) {
        //         int nrow = nr + dr[i];
        //         int ncol = nc + dc[i];
        //         if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
        //             vis[nrow][ncol] == iniColor) {
        //             vis[nrow][ncol] = color;
        //             q.push({nrow, ncol});
        //         }
        //     }
        // }


        //////DFS//////
        dfs(sr,sc,vis,dr,dc,color,iniColor,n,m);
        return vis;
    }
};