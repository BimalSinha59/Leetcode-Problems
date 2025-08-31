class Solution {
public:
   bool isSafe(char digit, int row, int col,vector<vector<char>>& board) {
        
        int n = board.size();
        for(int k=0; k<n; k++) {
            if(board[row][k] == digit) {
                
                return false;
            }
        }   
        
        for(int k=0; k<n; k++) {
            if(board[k][col] == digit) {
                
                return false;
            }
        }
       
        for(int k=0; k<n; k++) {
            if(board[3*(row/3)+k/3][3*(col/3)+k%3] == digit) {
                
                return false;
            }
        }
        
        return true;

    }
    bool solve(vector<vector<char>>& board) {
       
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                
                if(board[i][j] == '.' ) {
                    
                    for(char digit='1'; digit<='9'; digit++) {
                        
                        if(isSafe(digit,i,j, board) == true) {
                           
                            board[i][j] = digit;
                            
                            bool aageSolveHoPaya = solve(board);
                            if(aageSolveHoPaya == true) {
                               
                                return true;
                            }
                            else {
                               
                                board[i][j] = '.';
                            }
                        }
                    }
                   
                    return false;
                }
            }
        }
        
        return true;

    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};