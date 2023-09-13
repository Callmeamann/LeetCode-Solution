class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int candy = n , idx = 1;
        while(idx < n){
          if(ratings[idx] == ratings[idx-1]){
            idx++;
            continue;
          }
          int top = 0;
          while(ratings[idx] > ratings[idx-1]){
            idx++;
            top++;
            candy += top;
            if(idx==n)
              return candy;
          }
          int bottom = 0;
          while(idx<n && ratings[idx] < ratings[idx-1]){
            idx++;
            bottom++;
            candy +=bottom;
          }
          candy -= min(top,bottom);
        }
        return candy;
    }
};