class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    // int sum=0;
    // for(int i=0 ; i<nums.size() ; i++)
    // {
    //     sum^=i+1;
    //     sum^=nums[i];
    // }    
    // return sum^nums.size();
        vector<int> count(nums.size(),0);
        for(int i=0 ; i<nums.size();i++)
            count[nums[i]]++;
        

        for(int i=0;i<nums.size();i++)
        {
            if(count[i]>1)
                return i;
        }
        return 0;

    
    }
};