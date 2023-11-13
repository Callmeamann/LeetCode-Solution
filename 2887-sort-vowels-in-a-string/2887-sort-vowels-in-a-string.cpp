class Solution {
public:
    string sortVowels(string s) {
        string tmp = "";
        int i=0;
        set<char> st = {'A','E','I','O','U','a','e','i','o','u'};
        bool flag = false;
        for(auto &ch : s){
            if(st.find(ch) != st.end()){
                tmp.push_back(ch);
                flag = true;
            }
        }
        if(!flag)      
            return s;
        sort(tmp.begin(),tmp.end());
        
        for(auto &ch : s){
            if(st.find(ch) != st.end()){
                swap(ch,tmp[i]);
                i++;
            }
        }
        return s;

    }
};