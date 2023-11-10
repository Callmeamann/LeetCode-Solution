#include<set>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int maxCount = 0, n = st.size();
        for (int num : nums) {
            if(st.find(num-1) == st.end()){
                int count = 1;
                int tmp = num;
                while(st.find(tmp+1) != st.end()){
                    tmp++;
                    count++;
                }
                maxCount = max(maxCount,count);
            }
        }
        return maxCount;
    }
};
