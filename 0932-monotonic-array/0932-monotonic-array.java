class Solution {
    public boolean isMonotonic(int[] nums) {
        int n = nums.length;
        boolean up = false,down = false;

        for(int i=1 ; i<n ; ++i){
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
}