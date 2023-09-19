class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool up = false,down = false;

        for(int i=1 ; i<nums.size() ; ++i){
            if(nums[i] > nums[i-1]){
                up = true;
                if(down) return false;
            }
            else if( nums[i] < nums[i-1]){
                down = true;
                if(up) return false;
            }
        }
        return true;
    }
};