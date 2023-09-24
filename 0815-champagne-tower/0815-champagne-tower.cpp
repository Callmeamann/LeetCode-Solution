class Solution {
public:
    double champagneTower(int poured, int qRow, int query_glass) {
        vector<vector<double>> dp(qRow+1,vector<double>(qRow+1,0.0));
        dp[0][0] = poured ;
        for(int row =0 ; row<qRow ; ++row){
            for(int col = 0 ; col<qRow+1 ; ++col){
                double excess = (dp[row][col] - 1.0)/2.0;
                if(excess > 0){
                    dp[row+1][col] += excess;
                    dp[row+1][col+1] += excess;
                }
            }
        }
        // return min coz it may contain excess amount
        return min(1.0 , dp[qRow][query_glass]);
    }
};