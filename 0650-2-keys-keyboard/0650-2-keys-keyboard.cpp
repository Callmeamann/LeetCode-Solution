class Solution {
public:
    int minSteps(int n) {
        if(n<=5){
            return (n==1 ? 0 : n);
        }
        int m = 100000;
        int minq = 1,curr = n,ans=0;
        while(curr != 1){
            for(int j=1 ; j<=n ; ++j){
                if(curr % j == 0){
                    auto temp = curr/j;
                    if(temp != 1){
                        m = min(m,temp);
                        minq = j;
                    }
                }
            }
            ans += m;
            curr = minq;
            m = 1000;
        }
        return ans;
    }
};