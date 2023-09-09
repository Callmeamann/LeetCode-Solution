class Solution {
private:
    // Dynamic Programming Top - down approach
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
        // solve(nums,target);
        sort(nums.begin(), nums.end());
        vector<double> dp(target + 1, 0.0); // Use double for signed integer overflow

        dp[0] = 1.0;

        for (int csum = 1; csum <= target; csum++) {
            for (int n : nums) {
                if (csum - n >= 0) {
                    dp[csum] += dp[csum - n];
                } else {
                    break;
                }
            }
        }
        return static_cast<int>(dp[target]);
    }
};
