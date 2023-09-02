class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        if(s.size() == 0){
            return 0;
        }
        int l1 = s.size() , l2 = dictionary.size();
        set<string> st(dictionary.begin() , dictionary.end());
        vector<int> dp(l1+1,0);

        for(int i=1 ; i<=l1 ; i++){
            dp[i] = dp[i-1] +1;
            for(int j=i ; j>=1 ; j--){
                string temp = s.substr(j-1 , i-j+1);
                if(st.count(temp))
                    dp[i] = min(dp[i],dp[j-1]);
            }
        }
        return dp[l1];

    }
};