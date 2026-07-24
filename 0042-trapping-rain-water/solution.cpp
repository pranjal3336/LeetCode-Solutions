class Solution {
public:
    // vector<int>getleftMax(vector<int>&height , int n){
    //     vector<int>ans(n) ;
    //     ans[0] = height[0] ;

    //     for(int i=1 ; i<n ; i++){
    //         ans[i] = max(height[i] , ans[i-1]) ;
    //     }

    //     return ans ;
    // }
    // vector<int>getrightMax(vector<int>&height , int n){
    //     vector<int>ans(n) ;
    //     ans[n-1] = height[n-1] ;

    //     for(int i=n-2 ; i>=0 ; i--){
    //         ans[i] = max(height[i] , ans[i+1]) ;
    //     }

    //     return ans ;
    // }
    int trap(vector<int>& height) {
        //method 1 using TC O(N) and SC O(N)
        // int n = height.size() ;
        // vector<int>leftMax = getleftMax(height , n);
        // vector<int>rightMax = getrightMax(height , n);

        // int sum = 0 ;
        // for(int i=0 ; i<n ; i++){
        //     //yha width likhne ki need nhi thi kyonki width 1 hi hogi and area = l*b = l*1 = l hi aayga isliye direct sum mai l add kr rhe hai 
        //     int h = min(leftMax[i] , rightMax[i]) - height[i] ;

        //     sum+= h ;
        // }
        // return sum ;

        //method 2 using 2 pointer TC O(N) and SC O(1) 

        int n = height.size() ;
        int l=0 , r = n-1 ;
        int lmax = 0 , rmax = 0 ;
        int ans = 0;

        while(l<r){
            lmax = max(lmax , height[l]) ;
            rmax = max(rmax , height[r]) ;

            if(lmax <rmax){
                ans += lmax - height[l] ;
                l++ ;
            }
            else{
                ans += rmax - height[r] ;
                r-- ;
            }
        }

        return ans ;
    }
};
