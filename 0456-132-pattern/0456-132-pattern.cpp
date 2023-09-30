class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        // finding s1,s2 and s3 ,where s1<s3<s2 i.e. s3 stores 2nd largest number. 
        int s3 = INT_MIN;
        for(int i=nums.size()-1 ; i>=0 ; --i){
            if(nums[i] < s3)
                return true;
            // traversing stack to find 2nd largest and updating s3
            while(!st.empty() && nums[i]>st.top()){
                s3 = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};