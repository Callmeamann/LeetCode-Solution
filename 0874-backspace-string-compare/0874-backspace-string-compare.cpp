class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        int x=0 , y=0;
        for(int i=0 ; i<s.size() ; ++i){
            if(s[i] == '#'){
                if( x > 0)
                    x--;
            }    
            else{
                s[x++] = s[i];
             }   
        }
        for(int i=0 ; i<t.size() ; ++i){
            if(t[i] == '#'){
                if(y > 0)
                    y--;
            }
            else{            
                t[y++] = t[i];
            }
        }
        // cout<<x<<" "<<y;

        if(x!=y)
            return false;


        for(int i=0 ; i<x ; ++i){
            // cout<<s[i]<<" "<<t[i]<<endl;
            if(s[i] != t[i])
                return false;
        }
        return true;
    }
};