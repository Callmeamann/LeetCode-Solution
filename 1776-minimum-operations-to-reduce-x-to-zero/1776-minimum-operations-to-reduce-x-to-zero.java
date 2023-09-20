class Solution {
    public int minOperations(int[] nums, int x) {
        int n = nums.length;
        int currSum = 0, desSum = 0;
        int j=0, ans=0;
        for(int i=0 ; i<n ; ++i){
            desSum += nums[i];
        }
        desSum -= x;
        if(desSum == 0){
            return n;
        }
        for(int i=0 ; i<n ; ++i){
            currSum += nums[i];
            while(j<n && currSum > desSum)
                currSum -= nums[j++];
            if(currSum == desSum){
                ans = Math.max(ans,i-j+1);
            }
        }
        if(ans==0) return -1;
        return n-ans;
    }
}