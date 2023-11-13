class Solution {
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'o'|| c == 'u'|| c == 'i' 
            || c == 'A' || c == 'E' || c == 'O'|| c == 'U'|| c == 'I';
    }
public:
    string sortVowels(string s) {
        string tmp = "";
        int i=0;
        bool flag = false;
        for(auto &ch : s){
            if(isVowel(ch)){
                tmp.push_back(ch);
                ch = '#';
                flag = true;
            }
        }
        if(!flag)      
            return s;
        sort(tmp.begin(),tmp.end());
        
        for(auto &ch : s){
            if(ch == '#'){
                swap(ch,tmp[i]);
                i++;
            }
        }
        return s;

    }
};