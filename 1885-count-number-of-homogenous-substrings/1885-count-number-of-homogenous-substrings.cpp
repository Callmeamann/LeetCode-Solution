class Solution {
    int mod = 1e9+7;
public:
    int countHomogenous(string s) {
        int homoCount = 0;
        int i=0,n = s.size(); 
        while(i < n){
            int j=i+1;
            int count=1;
            while(s[i] == s[j]){
                j++;
                count++;
            }
            // cout<<"i "<<i<<" j "<<j<<" Cnt "<<count<<endl;
            // AP sum = n(n+1)/2
            homoCount = (homoCount + 1LL * count*(count + 1) / 2) % mod; 
            i=j;
        }

        return homoCount;
        
    }
};