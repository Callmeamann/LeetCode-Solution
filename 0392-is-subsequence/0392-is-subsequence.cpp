class Solution {
public:
    bool isSubsequence(string s, string t) {
        int si = 0, sn = s.size(),tn = t.size();
        if(sn > tn)
            return false;
        for(int i=0 ; i< tn; ++i){
            if(s[si] == t[i]){
                si++;
            }
            if(sn == si)
                return true;
        }
        if(si == sn)
            return true;
        return false;
    }
};