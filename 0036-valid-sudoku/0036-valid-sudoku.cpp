class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int rows = 9, cols = 9;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){

                char dig = board[i][j];
                if(dig == '.') continue;

                for(int col = 0; col < 9; col++){
                    if(col != j && board[i][col] == dig) return false;
                }

                
                for(int row = 0; row < 9; row++){
                    if(row != i && board[row][j] == dig) return false;
                }

               
                int srow = (i/3)*3;
                int scol = (j/3)*3;

                for(int r = srow; r < srow + 3; r++){
                    for(int c = scol; c < scol + 3; c++){
                        if((r != i || c != j) && board[r][c] == dig){
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};