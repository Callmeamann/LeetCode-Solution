class Solution {
private:
    bool isDigit(char ch){
        return ch>= '0' && ch<= '9' ;
    }
public:
    int myAtoi(string s) {
        const int l = s.size();
        if(l == 0)
            return 0;
        int idx = 0;
        while(idx <l && s[idx] == ' '){
            ++idx; 
        }
        if(idx == l)
            return 0;

        const int maxLim = INT_MAX/10;
        char ch ;
        bool isNeg = (ch = s[idx]) == '-';
        if(isNeg || ch == '+')
            ++idx;
        int result = 0;
        while(idx < l && isDigit(ch = s[idx])){
            int digit = ch - '0';
            if(result > maxLim || ( result == maxLim && digit > 7)){
                return isNeg? INT_MIN : INT_MAX;
            }

            result = result*10 + digit;
            ++idx;
        }
        return isNeg?-result:result;

    }
};