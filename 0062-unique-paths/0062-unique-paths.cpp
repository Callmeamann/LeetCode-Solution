class Solution {
public:
    int uniquePaths(int m, int n) {
        // combination of route

        if(m==1 || n==1)
            return 1;
        m--;
        n--;
        // m should always be larger of the two
        if(m<n)
            swap(m,n);
        long ans=1;
        int j=1;
        // Combination of m+n C n is calculated
        for(int i=m+1 ; i<=m+n ; i++,j++){
            ans *= i;
            ans /= j;
        }
        return ans;
    }
};