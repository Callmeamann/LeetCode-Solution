class Solution {
private:
    vector<vector<int>> dp;
    int sz;

    int solve(int idx , int remain, vector<int>& cost, vector<int>& time){
        if(remain <= 0)
            return 0;
        if(idx == sz)
            return 1e9;
        if(dp[idx][remain] != -1)   return dp[idx][remain];
        int paint = cost[idx] + solve(idx+1,remain-1-time[idx],cost,time);
        int notPaint = solve(idx+1,remain,cost,time);

        return dp[idx][remain] = min(paint,notPaint);
    }

public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        sz = cost.size();
        dp = vector<vector<int>>(sz,vector<int>(sz+1,-1));
        return solve(0,sz,cost,time);
    }
};