class Solution {
private:

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> rs(2,-1);
        int hi = nums.size() - 1;
        int low = 0;
        // base case
        if(nums.size() == 0)
            return rs;
        
        //left side
        while(low < hi){
            int mid = low + (hi - low) /2;
            if(target > nums[mid]){
                low = mid + 1;
            }else{
                hi = mid;
            }
        }
        if(target == nums[low]){
            rs[0] = low;
        }else{
            rs[0] = -1;
        }
        
        //right side
        hi = nums.size() - 1;
        while(low < hi){
            int mid = (low + (hi - low) /2 ) + 1;
            
            if(target < nums[mid]){
                hi = mid - 1;
            }else{
                low = mid;
            }
        }   
        if(target == nums[hi]){
            rs[1] = hi;
        }else{
            rs[1] = -1;
        }
        
        return rs;
    }
};