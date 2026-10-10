class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long ans = 0 ;
        int k = k1+k2 ;
        int n = nums1.size() ;
        vector<int>arr(1e5+1 , 0) ;//yha hum har differnece ki frequency store kr rhe hai 

        for(int i =0 ; i<n ; i++){
            int diff = abs(nums1[i]-nums2[i]) ;
            arr[diff]++ ;
            
        }
        for(int i=1e5 ; i>0 && k> 0 ; i--){
            int countopr = min(arr[i] , k) ;
            arr[i] -= countopr ;
            arr[i-1] += countopr ;
            k -= countopr ;
        }

        for(long long d=1 ; d<=1e5 ; d++){
            ans += ((d*d)*arr[d]) ;
        }

        return ans ;
       
    }
};
