class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        set<char> st;
        int i=0 , j=0 ;
        int mx = 0;
        while(j<n){
            if(st.find(s[j]) == st.end()){
                st.insert(s[j]);
                j++;
                mx = max(mx,j-i);
            }
            else{
                st.erase(s[i]);
                i++;
            }
        }
        return mx;
    }
};