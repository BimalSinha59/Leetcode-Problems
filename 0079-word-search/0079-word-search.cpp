class Solution {
public:
    vector<int> di = {0, 1, 0, -1};
    vector<int> dj = {1, 0, -1, 0};
    bool isValid(int i, int j, int& m, int& n) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }
    bool canBeConstructed(int i, int j, int& m, int& n, vector<vector<char>>& board, int idx, int& len, string& word) {
        if (idx == len) {
            return true;
        }
        if (!isValid(i, j, m, n) || board[i][j] != word[idx]) {
            return false;
        }
        bool ans = false;
        char temp = board[i][j];
        board[i][j] = '%';
        for (int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];
            ans |= canBeConstructed(ni, nj, m, n, board, idx + 1, len, word);
        }
        board[i][j] = temp;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int len = word.size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (canBeConstructed(i, j, m, n, board, 0, len, word)) {
                    return true;
                }
            }
        }
        return false;
    }
};