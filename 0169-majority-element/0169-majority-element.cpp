class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 1, mjrEle = nums[0];
        for(int i=1 ; i<n ; ++i){
            if(count == 0){
                count++;
                mjrEle = nums[i];
            }
            else if(mjrEle == nums[i])
                count++;
            else
                count--;
        }
        return mjrEle;

    }
};