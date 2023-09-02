class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        long long sum=0;
        long long I=1;
        // set<int> st;

        // while(n){
        //     if(st.find(I) == st.end()){
        //         st.insert(target-I);
        //         sum += I;
        //         n--;
        //     }
        //     I++;
        // }
        long long t = min(target/2,n);
        sum = (t*(t+1))/2;
        n -= t;
        while(n){
            sum += target;
            target++;
            n--;
        }

        return sum;
    }
};