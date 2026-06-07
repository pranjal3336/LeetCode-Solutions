class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //brute force approach TC O(N2) hai and SC O(1) hai 
        // int ans = INT_MIN  ;
        // int n = nums.size() ;
        // for(int i =0; i<n ; i++){
        //     int sum = 0 ;
        //     for(int j =i ; j<n ; j++){
        //         sum +=  nums[j] ;
        //         ans = max(ans , sum) ;
        //     }
        // }

        // return ans ;

        //now we use kadanes algorithm TC O(N) and SC O(n) 

        int sum = 0 ;
        int maxi = nums[0] ;
        int n = nums.size()  ;
        for(int i =0 ; i<n; i++){
            sum+=nums[i] ;
            maxi= max(maxi , sum) ;
            if(sum<0){//agr sum negative aa rha hai toh usse phir se 0 kr denge and uss i index se new array maankr aage bdenge 
                sum = 0 ;
            }
        }

        return maxi ;
    }
};
