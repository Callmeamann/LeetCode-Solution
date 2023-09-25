class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<vector<int>> freq(26,vector<int>(2,0));
        for(int i=0 ; i<t.size() ; ++i){
            if(i<s.size())
                freq[s[i]-'a'][0]++;
            freq[t[i]-'a'][1]++;
        }
        char ch = 'a';
        for(int i=0 ; i<26 ; ++i){
            if(freq[i][0] != freq[i][1]){
                ch = 'a'+i;
                break;                
            }
        }
        return ch;
    }
};