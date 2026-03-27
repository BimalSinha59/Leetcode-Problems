class Solution {
public:
    int di[4] = {-1, 0, 1, 0};
    int dj[4] = {0, 1, 0, -1};
    bool solve(int i, int j, int idx, int& n, int& m, int sz, vector<vector<char>>& board, string& word) {
        if (idx == sz) {
            return true;
        }
        if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] != word[idx] ||
            board[i][j] == '#') {
            return false;
        }
        char ch = board[i][j];
        board[i][j] = '#';
        for (int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];
            if (solve(ni, nj, idx + 1, n, m, sz, board, word)) {
                return true;
            }
        }
        board[i][j] = ch;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0] && solve(i, j, 0, n, m, word.size(), board, word)) {
                    return true;
                }
            }
        }
        return false;
    }
};