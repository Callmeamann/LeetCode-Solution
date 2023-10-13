

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size() , fir = cost[0] , sec = cost[1];
        if(n < 2)
            return min(fir,sec);
        
        for(int i=2 ; i<n ; ++i){
            int curr = cost[i] + min(fir,sec);
            fir = sec;
            sec = curr;
        }
        return min(fir,sec);
    }
};