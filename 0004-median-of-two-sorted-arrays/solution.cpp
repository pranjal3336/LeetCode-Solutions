class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans ;
        int i =0 ;
        int j =0;
        int m = nums1.size();
        int n = nums2.size();

        while(i<m && j<n){
            if(nums1[i]>nums2[j]){
                ans.push_back(nums2[j]);
                j++;
            }
            else{
                ans.push_back(nums1[i]);
                i++;
            }
        }

        while(i<m){
            ans.push_back(nums1[i]);
            i++;
        }
        while(j<n){
            ans.push_back(nums2[j]);
            j++;
        }

        int  x = ans.size();

        double b = ans[x/2] + ans[(x-2)/2] ;
        double c = b/2  ;




        if(x%2!=0){
            return ans[x/2] ;
        }

        else{
            return c ;
        }


    }
};
