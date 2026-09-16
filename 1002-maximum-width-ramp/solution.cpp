class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        // int n =  nums.size() ;
        // int maxi = INT_MIN ;
        // for(int i=0 ; i<n ; i++){
        //     int j = n-1 ;
        //     while(nums[i]>nums[j] && j>=i){
        //         j-- ;
        //     }
        //     maxi = max(maxi , j-i) ;

        // }
        // if(maxi == INT_MIN){
        //     return 0 ;
        // }
        // return maxi ;

        int n = nums.size() ;
        vector<int>rightmax(n,0) ; 
        rightmax[n-1] = nums[n-1] ;

        for(int i=n-2 ; i>=0 ;i--){
            rightmax[i] = max(rightmax[i+1] , nums[i]) ;
           
        }
       
        int j = 0 ;
        int maximum = 0 ;
        for(int i =0 ; i<n ; i++){
            while(j<n && nums[i]<=rightmax[j] ){
                j++ ;
            }
            maximum = max(maximum , j-i) ;
        }
        return maximum-1;
    }
};
