class Solution {
private:

bool isSafe(int n,int col,int row,vector<string> &board){
    int R = row;
    int C = col;

    while(row >=0 && col>=0){
        if(board[row][col] == 'Q') 
            return false;
        row--;
        col--;
    }
    row = R;
    col = C;

    while(col>=0){
        if(board[row][col] == 'Q')
            return false;
        col--;
    }
    col = C;

    while(row<n && col>=0){
        if(board[row][col] == 'Q')
            return false;
        row++;
        col--;
    }
    return true;
}

void solve(int col,int n,vector<string> &board,vector<vector<string>> &ans){
    if(col >= n){
        ans.push_back(board);
        return ;
    }

    for(int row = 0 ; row<n ; row++){
        if(isSafe(n,col,row,board)){
            board[row][col] = 'Q';
            solve(col+1,n,board,ans);
            board[row][col] = '.';
        }
    }
}


public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0 ; i<n ; i++){
            board[i] = s;
        }
        solve(0,n,board,ans);
        return  ans;
    }

};