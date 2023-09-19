class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        bool up = false,down = false;

        for(int i=1 ; i<nums.size() ; ++i){
            if(nums[i] > nums[i-1]){
                up = true;
            }
            else if( nums[i] < nums[i-1]){
                down = true;
            }
            if(up && down)
                return false;
        }
        return true;
    }
};