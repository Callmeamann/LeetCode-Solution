class Solution {
private:
    void transpose(vector<vector<int>> &matrix , int n){
        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){
                if(i!=j)
                {
                    swap(matrix[i][j] , matrix[j][i]);
                }
            }
        }
    }


public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        reverse(matrix.begin(),matrix.end());
        transpose(matrix,n);

        // for(int i=0 ; i<n ; i++){
        //     for(int j=0 ; j<n/2 ; j++){
        //         swap(matrix[i][j],matrix[i][n-j-1]);
        //     }
        // }
    }
};