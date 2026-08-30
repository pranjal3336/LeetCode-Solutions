class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size() ;
        // int mini = INT_MAX ;
        // int maxi = INT_MIN ;
        // int i =0 ;
        // while(i<n ){
        //     mini = min(nums[i] , mini) ;
        //     maxi = max(nums[i] , maxi) ;
        //     i++ ;
        // }
        // int x  ;//index of minimum element 
        // int y ;//index of maximum element 
        // for(int i =0 ; i<n ; i++){
        //     if(nums[i] == mini){
        //         x = i ;
        //     }
        //     if(nums[i] == maxi){
        //         y = i ;
        //     }

        // }

        //upr ke logic ko short mai likh skte hai using stl functions 

        
        // Minimum element ka index
        int x = min_element(nums.begin(), nums.end()) - nums.begin();

        // Maximum element ka index
        int y = max_element(nums.begin(), nums.end()) - nums.begin();


       int opt1 = max(x , y)+1 ;//agr front se delte kre toh
       int opt2 = n - min(x,y) ;//agr back se delte kre toh

       int opt3 = min(x,y)+1+n-max(x,y) ;//agr dono side se delete kre toh 

       return min(opt1 , min(opt2 , opt3)) ;//minimum of all three options 
    }
};
