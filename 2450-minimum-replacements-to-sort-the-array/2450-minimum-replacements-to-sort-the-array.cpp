class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        int last = nums[n-1];
        long long opr = 0;
        for(int i=n-2 ; i>=0 ; i--){
            if(nums[i] > last){
                // if(nums[i]%last == 0){
                //     opr += nums[i]/last -1;
                // }
                // else{
                //     long long x = nums[i]/last;
                //     nums[i] = nums[i] - (last*(x-1));
                //     last = min(nums[i]/2,nums[i] - (nums[i]/2));
                //     opr += x;
                // }
                int temp = nums[i]/last;
                if(nums[i]%last != 0)
                    temp++;
                last = nums[i]/temp;
                opr += temp-1;

            }
            else{
                last = nums[i];
            }
        }
        return  opr;
    }
};