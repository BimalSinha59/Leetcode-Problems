class Solution {
public: 
    bool isValid(int r, int c, vector<vector<char>>& board, char value){
        int cnt=0;
        for(int i=0; i<9; i++){
            if(board[r][i]==value){
                cnt++;
            }
            if(board[i][c]==value){
                cnt++;
            }
            if(board[3*(r/3)+(i/3)][3*(c/3)+(i%3)]==value){
                cnt++;
            }
            if(cnt>3){
                return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]!='.' && (!isValid(i,j,board,board[i][j]))){
                    return false;
                }
            }
        }
        return true;
    }
};