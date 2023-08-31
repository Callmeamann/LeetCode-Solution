class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // vector<int> ans(nums1.size()+nums2.size());
        // vector<int>::iterator it;
        // it = set_union(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),ans.begin());
        // sort(ans.begin(),ans.end());
        // int x = nums1.size()+nums2.size();
        // if(x%2==1){
        //     return ans[x/2];
        // }
        // else{
        //     return double(ans[x/2-1] + ans[x/2])/2.0;
        // }

        int n = nums1.size() , m = nums2.size();
        if(n < m)
            return findMedianSortedArrays(nums2,nums1);

        int low =0, high =m*2;
        while(low<=high){
            int m2 = (high+low)/2;
            int m1 = n+m-m2;

            double l1 = (m1 == 0)? INT_MIN :nums1[(m1-1)/2];
            double l2 = (m2 == 0)? INT_MIN :nums2[(m2-1)/2];
            double r1 = (m1 == n*2)? INT_MAX :nums1[m1/2];
            double r2 = (m2 == m*2)? INT_MAX :nums2[m2/2];


            if(l1 > r2) 
                low = m2 +1;
            else if(l2 >r1) 
                high = m2-1;
            else 
                return (max(l1,l2) + min(r1,r2))/2;
        } 
        return -1;
    }
};