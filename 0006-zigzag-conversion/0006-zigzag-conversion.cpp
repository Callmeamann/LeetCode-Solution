class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        
        int n = s.size();
        string ans = "";
        for(int r=0 ; r<numRows ; ++r){
            int x = (numRows - 1)*2;
            if(r==0 || r==numRows-1){
                int i=r;
                while(i<n){
                    ans += s[i];
                    i += x;
                }
            }
            else{
                int i=r;
                while(i<n){
                    ans += s[i];
                    i += x - 2*r;
                    if(i>=n)
                        break;
                    ans += s[i];
                    i += 2*r;
                }
            }
        }
        return ans;
    }
};