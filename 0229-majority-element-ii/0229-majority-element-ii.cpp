class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int> mp;

        int n = nums.size();
        for(int i=0 ; i<n ; ++i){
            mp[nums[i]]++;
        }
        // for(auto m : mp){
        //     cout<<m.first<<" "<<m.second<<endl;
        // }
        vector<int> res;
        int n3 = n/3;
        for(auto m : mp){
            if(m.second > n3)
                res.push_back(m.first);
        }
        return res;
    }
};