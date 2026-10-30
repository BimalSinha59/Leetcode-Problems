class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int rows = image.size();
        int cols = image[0].size();
        int oldColor = image[sr][sc];

        if (oldColor == color) {
            return image;
        }

        vector<int> deltaRow = {-1, 1, 0, 0};
        vector<int> deltaCol = {0, 0, -1, 1};
        queue<pair<int, int>> q;

        image[sr][sc] = color;

        q.push({sr, sc});

        while (!q.empty()) {
            pair<int, int> cell = q.front();
            q.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nextRow = cell.first + deltaRow[dir];
                int nextCol = cell.second + deltaCol[dir];

                if (nextRow >= 0 && nextRow < rows && nextCol >= 0 &&
                    nextCol < cols) {
                    if (image[nextRow][nextCol] == oldColor) {
                        image[nextRow][nextCol] = color;
                        q.push({nextRow, nextCol});
                    }
                }
            }
        }

        return image;
    }
};