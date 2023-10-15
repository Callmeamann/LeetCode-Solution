#define mod (int)(1e9+7)
class Solution {
private:
    vector<vector<int>> dp;
    int n;
    int solve(int curr, int remain){
        if(remain == 0){
            if(curr == 0)
                return 1;
            return 0;
        }
        if(dp[curr][remain] != -1)
            return dp[curr][remain];

        int ans = solve(curr,remain-1);
        if(curr > 0){
            ans = (ans + solve(curr-1,remain-1)) % mod;
        }
        if(curr < n-1){
            ans = (ans + solve(curr+1,remain-1)) % mod;
        }
        return dp[curr][remain] = ans;
    }
public:
    int numWays(int steps, int arrLen) {
        arrLen = min(steps,arrLen);
        n=arrLen;
        dp = vector(arrLen,vector(steps+1,-1));
        // answer at dp(0,steps)
        return solve(0,steps);

    }
};