class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26,0);

        for(int i=0 ; i<s.size() ; i++){
            freq[s[i]-'a']++;
        }
        int count = 0;
        unordered_set<int> st;
        for(int i=0 ; i<26 ; i++){
            while(freq[i] and st.find(freq[i]) != st.end()){
                freq[i]--;
                count++;
            }
            st.insert(freq[i]);
        }       
        return count;
    }
};