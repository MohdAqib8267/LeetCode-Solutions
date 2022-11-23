class Solution {
public:
    bool isSafe(int row,int col,vector<vector<char>>& board,char val){
         for(int i=0; i<9; i++) {
            // row check 
            if(board[row][i]==val) 
                return false;
            
            // col check
            if(board[i][col]==val) 
                return false;
            
            // 3*3 matrix check
            if(board[3*(row/3) + i/3][3*(col/3) + i%3]==val) 
                return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        
         for(int row=0; row<9; row++) {
            for(int col=0; col<9; col++) {
                // cell empty
                if(board[row][col]=='.') {
                    for(int val=1; val<=9; val++) {
                        if(isSafe(row,col,board,val+'0')) {
                            board[row][col]=val+'0';
                            // recursive call
                            bool nextPossibleSolution = solve(board);
                            if(nextPossibleSolution) 
                                return true;
                            else {
                                // backtrack
                                board[row][col]='.';
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