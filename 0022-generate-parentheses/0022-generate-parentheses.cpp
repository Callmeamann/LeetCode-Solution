class Solution {
private:  
    void solve(vector<string>& result ,string str, int left , int right){
        if(left == 0 && right == 0){
          result.push_back(str);
          return;
        }
        if(right > 0)
          solve(result , str+")" ,left , right-1);
        if(left > 0)
          solve(result , str+"(", left-1,right+1);
        
        return;
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        solve(result,"",n,0);
        return result;
    }

};