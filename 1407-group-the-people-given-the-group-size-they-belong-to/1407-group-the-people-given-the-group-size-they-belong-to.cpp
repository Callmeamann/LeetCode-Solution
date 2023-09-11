class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        unordered_map<int,vector<int>> mp;

        for(int i=0 ; i<groupSizes.size() ; i++){
            int id = groupSizes[i];
            mp[id].push_back(i);
            if(mp[id].size() == id){
                ans.push_back(mp[id]);
                mp.erase(id);
            }
        }

        return ans;

    }
};