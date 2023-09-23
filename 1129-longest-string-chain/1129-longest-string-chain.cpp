bool cmp(const string lhs, const string rhs) {
   return lhs.length() < rhs.length();
}
// class Solution {
// private:
//     bool isSubsequence(string &s1, string &s2){
//         int n = s1.length(), m = s2.length();
//         int i = 0, j = 0;
//         while (i < n && j < m) {
//             if (s1[i] == s2[j])
//                 i++;
//             j++;
//         }
//         // cout<<" yes ";
//         return i == n;
//     }
// public:
//     int longestStrChain(vector<string>& words) {
//         sort(words.begin(),words.end(),cmp);
//         int maxChain = 1;
//         int n = words.size();
//         for(int i=0 ; i<n ; ++i){
//             int currCount = 1;
//             int wordsx = words[i].size();
//             string prev = words[i];
//             for(int j=i+1 ; j<n ; ++j){
//                 if(wordsx == words[j].size())
//                     continue;
//                 if(wordsx +1 < words[j].size())
//                     break;
//                 if(isSubsequence(prev,words[j])){
//                     cout<<prev<<" ";
//                     prev = words[j];
//                     wordsx = prev.size();
//                     currCount++;
//                 }
//             }
//             cout<<endl;
//             if(maxChain >= n-i)
//                 break;
//             // cout<<currCount<<endl;
//             maxChain = max(maxChain,currCount);
//         }
//         return maxChain;
//     }
// };
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin() , words.end(),cmp);
        unordered_map<string,int> mp;
        int maxChain = 0;

        for(auto word : words){
            mp.insert({word,1});
            for(int i=0 ; i<word.size() ;   ++i){
                string next = word;
                next.erase(next.begin()+i);
                // cout<<next<<" ";
                if(mp.find(next)!=mp.end() && mp[next] +1 >mp[word]){
                    mp[word] = mp[next] +1;
                }
            }
            maxChain = max(maxChain,mp[word]);
            // cout<<endl;           
        }
        return maxChain;
    }
};