class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int diff = INT_MAX;
        int ans = 0;
        int n = nums.size();
        for(int i=0 ; i<n ; ++i){
            // for(int j=i+1 ; j<n-1 ; ++j){
            //     for(int k=j+1 ; k<n ; ++k){
            //         int sum = nums[i] + nums[j]  + nums[k];
            //         if(diff > abs(target-sum)){
            //             diff = abs(target - sum);
            //             ans = sum;
            //         }
            //     }
            // }
            // time complexity = O(nlogn)
            int low = i+1,high = n-1;
            while(low<high){
                int sum = nums[low]+nums[high]+nums[i];
                if(diff > abs(target - sum)){
                    ans = sum;
                    diff = abs(target - sum);
                }
                if(sum > target){
                    high--;
                }
                else if(sum<target){
                    low++;
                }
                else{
                    return target;
                }
            }
        }
        return ans;
    }
};