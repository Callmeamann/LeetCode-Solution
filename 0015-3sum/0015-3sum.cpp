class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0 ; i <nums.size() ; ++i){
            int target = nums[i];
            int low = i+1;
            int high = nums.size()-1;
            // Binary Search to the pair which when added with target results in 0
            while(low<high){
                int sum = nums[low] + nums[high] + target;
                if(sum > 0)     high--;
                else if(sum < 0)    low++;
                else{
                    vector<int> tmp = {target,nums[low],nums[high]};
                    ans.push_back(tmp);
                    while(low < high && nums[low] == tmp[1]) low++;
                    while(low < high && nums[high] == tmp[2]) high--;
                }
            }
            while(i+1 < nums.size() && target == nums[i+1]) i++;
        }
        return ans;
    }
};