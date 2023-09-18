class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> count;
        int n = mat.size(), m = mat[0].size();
        for(int i=0 ; i<n ; ++i){
            int c = 0;
            for(int j=0 ; j<m ; ++j){
                if(mat[i][j] == 1)
                    c++;
                else
                    break;
            }
            count.push_back({c,i});
        }
        sort(count.begin(),count.end());
        vector<int> ans;
        for(int i=0 ; i < k ; i++){
            ans.push_back(count[i].second);
        }
        return ans;
    }
};