class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        int cols = ceil(n / (double)rows);
        vector<vector<char>> mat(rows, vector<char>(cols, '&'));
        int idx = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                mat[i][j] = encodedText[idx];
                idx++;
            }
        }
        string ans;
        for (int j = 0; j < cols; j++) {
            int add = 0;
            for (int i = 0; i < rows; i++) {
                int ni = i;
                int nj = j + add;
                if (ni < rows && nj < cols) {
                    ans.push_back(mat[ni][nj]);
                }
                add++;
            }
        }
        while (!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }
        return ans;
    }
};