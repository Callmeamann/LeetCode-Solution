class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        // dp stores the max no. of taps possible + 1
        vector<int> dp(n+1,n+2);
        dp[0]=0;
        for(int i=0 ; i<=n ; i++){
            for(int j = max(0,i-ranges[i]+1) ; j<=min(n,ranges[i]+i) ; j++){
                dp[j] = min(dp[j],dp[max(0,i-ranges[i])] +1);
            }
        }
        return dp[n] < n+2? dp[n] : -1;
    }
};