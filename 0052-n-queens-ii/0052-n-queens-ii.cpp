class Solution {


void solve(int col, int n, vector<string> &board,vector<int> &left,vector<int> &upper,vector<int> &lower,int &count){
    //base
    if(n<=col){
        count++;
        return ;
    }
    //iterate
    for(int row =0 ; row<n ; row++){
        if(left[row] == 0 && upper[n-1+col-row] ==0 && lower[row+col] == 0){
            left[row] = 1;
            upper[n-1+col-row] = 1 ;
            lower[col+row] = 1;
            board[row][col] = 'Q';
            solve(col+1,n,board,left,upper,lower,count);
            left[row] = 0;
            upper[n-1+col-row] = 0 ;
            lower[col+row] = 0;
            board[row][col] = '.';
        }
    }
}


public:
    int totalNQueens(int n) {
        int count=0;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0 ; i<n ; i++){
            board[i] = s;
        }
        vector<int> left(n,0),upper(n*2 -1,0) , lower(n*2 - 1,0);
        solve(0,n,board,left,upper,lower,count);
        return count;
    }
};


