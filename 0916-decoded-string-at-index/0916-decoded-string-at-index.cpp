class Solution {
public:
    string decodeAtIndex(string s, int k) {
        int n = s.size();
        long long len = 0;
        // for(int idx = 0 ;idx < n; ++idx){
        //   if(isdigit(s[idx])){
        //     len *= s[idx]-48;
        //   }
        //   else{
        //     len++;
        //   }
        // }
        int i=0;
        while(len<k){
          if(isdigit(s[i]))
            len *= s[i]-48;
          else
            len++;
          i++;
        }
        cout<<len;
        for(int idx=i-1 ; idx>=0 ; --idx){
          if(isdigit(s[idx])){
            len /= s[idx]-48;
            k %= len;
          }
          else{
            if(k==0 || len==k){
              return string(1,s[idx]);
            }
            len--;
          }
        }
        return "-1";
    }
};