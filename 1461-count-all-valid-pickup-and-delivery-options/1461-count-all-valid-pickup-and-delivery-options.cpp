
class Solution {
private:
    long N = 1e9+7 ;
    int x = 500;
    static vector<vector<int>> dp;
    long combination(int unpicked , int undelivered){
    
    if(unpicked == 0 and undelivered == 0 ){
        return 1;
    }
    if(unpicked < 0 or undelivered < 0 or unpicked > undelivered){
        return 0;
    }
    if(dp[unpicked][undelivered]){
        return dp[unpicked][undelivered] ;
    }

    long ans = 0;
    ans += unpicked * combination(unpicked-1 , undelivered);
    ans %= N;
    ans += (undelivered - unpicked) * combination(unpicked,undelivered-1);
    ans %= N;

    return dp[unpicked][undelivered] = ans;
    }

public:

    Solution() {
        dp.resize(x + 1, vector<int>(x + 1, 0));
    }

    int countOrders(int n) {
        return combination(n,n);
    }
};
vector<vector<int>> Solution::dp;