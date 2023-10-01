class Solution {
private:
    void revWord(string &str, int l,int r){
      while(l<r){
        swap(str[l++],str[r--]);
      }
    }
public:
    string reverseWords(string s) {
        int i=0 ,n=s.length();
        int ti=0;
        
        while(i<n){
          if(s[i] == ' '){
            revWord(s,ti,i-1);
            i++;
            ti = i;
            continue;
          }
          i++;
        }
        revWord(s,ti,n-1);
        return s;

    }
};