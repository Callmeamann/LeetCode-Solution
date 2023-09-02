class Solution {
private:

    bool isValid(vector<vector<char>>& board,int row ,int col ,char ch){
        // for(int c=col ; c<board[0].size() ; c++){
        //     if(board[row][c] == ch)
        //         return false;
        // }
        // for(int r=row ; r<board.size() ; r++){
        //     if(board[r][col] == ch)
        //         return false;
        // }
        // for(int i=0 ; i<3 ; i++){
        //     for(int j=0 ; j<3 ; j++){
        //         if(board[i][j] == ch)
        //             return false;
        //     }
        // }
        for(int i=0 ; i<9 ; i++){
            if(board[row][i] == ch)
                return false;
            if(board[i][col] == ch)
                return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3] == ch)
                return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board){
        for(int i=0 ; i<board.size() ; i++){
            for(int j=0 ; j<board[0].size() ; j++){
                if(board[i][j] == '.'){

                    for(char ch = '1'; ch<='9' ; ch++){
                        if(isValid(board,i,j,ch)){
                            board[i][j] = ch;
                            if(solve(board))
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};