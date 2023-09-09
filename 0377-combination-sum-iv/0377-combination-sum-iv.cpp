class Solution {
private:
    unordered_map<int,int> umap;
    int solve(vector<int>& nums,int remain){
        if(remain == 0)
            return 1;
        if(umap.count(remain))
            return umap[remain];
        
        int sum = 0;
        for(auto n : nums){
            if(remain - n >= 0){
                sum += solve(nums,remain - n);
            }
        }
        umap[remain] = sum;
        return sum;
    }

public:
    int combinationSum4(vector<int>& nums, int target) {
        return solve(nums,target);
    }
};