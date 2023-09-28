class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size() < 2)
            return chars.size();
        
        int i=0 , j=0;
        int n = chars.size();
        while(i<n){
            
            int count=0;
            chars[j] = chars[i];
            while(i<n && chars[j] == chars[i]){
                count++;
                i++;
            }
            if(count == 1){
                ++j;
                continue;
            }
            cout<<count<<endl;
            string s = to_string(count);
            for(auto ch :s){
                chars[++j] =ch;
            }
            j++;
        }
        return j;
    }
};