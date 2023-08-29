class Solution {
public:
    int bestClosingTime(string customers) {
        int x = customers.size();
        vector<int> suffix(x) , prefix(x);
        int y=0,n=0;
        for(int i=0 ; i<x ; i++){
            if(customers[i] == 'N'){
                n++;
            }
            prefix[i] = n;
            if(customers[x-i-1] == 'Y'){
                y++;
            }
            suffix[x-i-1] = y;
        }

        if(prefix[x-1] == x)
            return 0;
        int minHour = 0;
        int count = prefix[0] + suffix[0];
        for(int i=1 ; i<x ; i++){
            int currCount = prefix[i] + suffix[i];
            if(currCount < count){
                count = currCount;
                minHour = i;
            }
        }
        if(minHour == 0 and customers[0] == 'N'){
            return 0;
        }
        return minHour + 1;
    }
};