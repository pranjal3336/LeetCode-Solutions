class Solution {
public:
    int maxProduct(vector<int>& nums) {
      //method 1 using brute force TC O(N2) and SC O(1)
    //   int n = nums.size() ;
    //   int maxi = INT_MIN ;
    //   for(int i =0 ; i<n ; i++){
    //     int product = 1 ;
    //     for(int j = i ; j<n ; j++){
    //         product *= nums[j] ;
    //         maxi = max(maxi , product) ;
    //     }
    //   }
    //   return maxi ;

      //method 2 hum left to right  product nikalenge jisse prefix bolenege and right to left bhi product nikalenge and dono ko maxi se compae krte rhenge 

      //negative number ek trh se array ko two part mai divide kr rha hai left and right and dono mai se jha maximum product millega vhi answer hoga 
      //and 0 array ko multiple array mai split kr rha hai isliye 0 aate hi prefix ya suffix wala product 0 ho jayga isliye isse dubara se 1 initialize kr denge 

      int maxi = INT_MIN ;
      int n = nums.size() ;
      int prefix = 1 ;
      int suffix = 1 ;
        // for(int i = 0 ; i< n ; i++){
        //     prefix *= nums[i] ;
        //     maxi = max(maxi , prefix) ;

        //     if(prefix == 0){//jaise hi 0 aaya prefix ko 1 se initialize kr denge 
        //         prefix = 1 ;
        //     }
        // }
        // for(int i = n-1 ; i>=0 ; i--){
        //     suffix *= nums[i] ;
        //     maxi = max(maxi , suffix) ;

        //     if(suffix == 0){
        //         suffix = 1 ;
        //     }
        // }

        // return maxi ;

        //2 loop ki jgh ek loop mai kaam ho skte hai 
        for(int i = 0 ; i<n ; i++){
            prefix *= nums[i] ;
            suffix *= nums[n - (i + 1) ] ;//yha se hum ek sath shuru and end dono se traverse kr rhe hai 

            maxi = max(maxi , max(prefix , suffix)) ;

            if(prefix == 0){//jaise hi 0 aaya prefix ko 1 se initialize kr 
            prefix = 1; 
             }

             if(suffix == 0){ //suffix = 1 ;
             suffix = 1; 
            }

        }
        return maxi ;



    }
};
