class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
    //    int num = 1 ;
        // int n = arr.size() ;
    //    int i = 0 ;
    //    while(i<n && k >0 ){
    //         if(arr[i] == num){
    //             i++ ;
    //         }
    //         else{
    //             k-- ;
    //         }
    //         num++ ;
    //    } 

    //    //edge case like [1,2,3] k =2 hoga toga toh yha k-- hua hi nhi giga num = 3 tk pahucg gya hoga pr hum k-- krenge taaki num =5 tk aa jaaye and num ek aage bd gya hoga num -1 krenge 
    //    while(k--){
    //         num++ ;
    //    }
    //    return num-1 ;

    //using binary search 
        int n = arr.size() ;
        int l = 0 ;
        int r = n-1 ;
        while(l<=r){
            int mid = l+(r-l)/2 ;
            int missingtillnow = arr[mid] - (mid+1) ;
            if(missingtillnow < k){
                l = mid+1 ;
            }
            else{
                r = mid-1 ;
            }
        }

        return l + k ;
    }
};
