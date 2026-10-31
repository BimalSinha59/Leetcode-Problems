class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int fresh = 0;
        int minutes = 0;
        queue<pair<int, int>> q;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == 2) {
                    q.push({row, col});
                } else if (grid[row][col] == 1) {
                    fresh++;
                }
            }
        }

        vector<int> dRow = {-1, 1, 0, 0};
        vector<int> dCol = {0, 0, -1, 1};

        while (!q.empty() && fresh > 0) {
            int levelSize = q.size();

            for (int count = 0; count < levelSize; count++) {
                auto [row, col] = q.front();
                q.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int nextRow = row + dRow[dir];
                    int nextCol = col + dCol[dir];

                    if (nextRow >= 0 && nextCol >= 0 && nextRow < rows &&
                        nextCol < cols && grid[nextRow][nextCol] == 1) {
                        grid[nextRow][nextCol] = 2;
                        fresh--;
                        q.push({nextRow, nextCol});
                    }
                }
            }

            minutes++;
        }

        if (fresh > 0) {
            return -1;
        }

        return minutes;
    }
};